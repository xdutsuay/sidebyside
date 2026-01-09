import os
import sys
import json
import concurrent.futures
import urllib.request
import urllib.error
import argparse
from pathlib import Path

# Configuration
OLLAMA_URL = "http://localhost:11434/api/generate"
MODEL_NAME = "phi3:mini" 
SOURCE_EXTENSION = ".py"
TARGET_LANGS = {
    "cpp": ".cpp",
    "js": ".js",
    "rs": ".rs",
    "go": ".go"
}
SKIP_DIRS = {".git", ".github", ".vscode", "_learn", "scripts", "__pycache__", ".devcontainer", "tests", "docs"}

def query_ollama(prompt, model=MODEL_NAME):
    data = {"model": model, "prompt": prompt, "stream": False}
    try:
        req = urllib.request.Request(
            OLLAMA_URL, 
            data=json.dumps(data).encode('utf-8'), 
            headers={'Content-Type': 'application/json'}
        )
        with urllib.request.urlopen(req, timeout=300) as response:
            return json.loads(response.read().decode()).get('response', '')
    except Exception as e:
        return f"Error: {e}"

def clean_code_block(text, lang_ext):
    """
    Extracts code from markdown code blocks in LLM response.
    """
    if "```" not in text:
        return text
    
    lines = text.split('\n')
    in_block = False
    code_lines = []
    
    # Try to find block with correct language tag
    lang_tag = lang_ext.replace('.', '')
    for line in lines:
        if line.strip().startswith("```"):
            if in_block:
                break # End of block
            else:
                # Start of block - check if it matches our language or is generic
                if len(line) > 3:
                     if lang_tag in line.lower():
                         in_block = True
                         continue
                # If we haven't found a specific block yet, maybe this is a generic one, 
                # but let's prefer specific ones. 
                # Simple logic: take first block if no specific one found? 
                # Let's just take the first block that starts with ```[lang] or just ```
                in_block = True 
                continue
        
        if in_block:
            code_lines.append(line)
            
    if not code_lines:
        # Fallback: just return everything inside first ``` pair found
        in_block = False
        for line in lines:
             if line.strip().startswith("```"):
                 if in_block: break
                 in_block = True
                 continue
             if in_block:
                 code_lines.append(line)

    return "\n".join(code_lines)

def convert_file(file_path, lang, ext):
    print(f"  [Converting] {file_path.name} -> {lang.upper()}...")
    try:
        with open(file_path, 'r') as f:
            source_code = f.read()
            
        prompt = f"""
You are an expert programmer. Convert the following Python code to idiomatic {lang}.
Ensure the code is complete, compiles/runs, and includes a main function/example usage if applicable.
Do not wrap in markdown if possible, or use standard markdown code blocks.

Python Source ({file_path.name}):
```python
{source_code}
```
"""
        response = query_ollama(prompt)
        cleaned_code = clean_code_block(response, ext)
        
        target_path = file_path.with_suffix(ext)
        if target_path.exists():
            print(f"    [Skip] {target_path} already exists")
            return
            
        with open(target_path, 'w') as f:
            f.write(cleaned_code)
            
    except Exception as e:
        print(f"    [Error] Failed to convert {file_path} to {lang}: {e}")

def create_learning_exercise(file_path, lang, ext, learn_root):
    print(f"  [Learning] {file_path.name} -> {lang.upper()} Exercise...")
    try:
        # We need the converted file content first
        converted_path = file_path.with_suffix(ext)
        if not converted_path.exists():
             # Try to generate it if missing (chicken/egg problem handled by process_file order)
             return 

        with open(converted_path, 'r') as f:
            converted_code = f.read()

        prompt = f"""
You are a teacher. Take this {lang} code and transform it into a "Fill in the Blanks" exercise.
Replace CRITICAL logic parts with '____________' (12 underscores).
Do not remove imports or boilerplate, only the algorithmic logic.
Add comments explaining what needs to be filled.

Code:
```
{converted_code}
```
"""
        response = query_ollama(prompt)
        cleaned_code = clean_code_block(response, ext)
        
        # Structure: _learn/<algo_name>/<lang>_exercise.<ext>
        algo_name = file_path.stem
        learn_dir = learn_root / algo_name
        learn_dir.mkdir(parents=True, exist_ok=True)
        
        exercise_path = learn_dir / f"{lang}_exercise{ext}"
        
        with open(exercise_path, 'w') as f:
            f.write(cleaned_code)

    except Exception as e:
        print(f"    [Error] Failed to create exercise for {file_path}: {e}")

def process_file(file_path, learn_root):
    print(f"Processing {file_path}...")
    
    # We can parallelize languages for a single file
    with concurrent.futures.ThreadPoolExecutor(max_workers=1) as executor:
        futures = []
        for lang, ext in TARGET_LANGS.items():
            # 1. Conversion
            futures.append(executor.submit(convert_file, file_path, lang, ext))
        
        concurrent.futures.wait(futures)
        
        # 2. Learning Exercises (sequentially after conversion to ensure files exist)
        # Re-using the same executor/thread might be tricky if we depend on disk write. 
        # Let's just do it sequentially here for safety.
        for lang, ext in TARGET_LANGS.items():
             create_learning_exercise(file_path, lang, ext, learn_root)

def main():
    parser = argparse.ArgumentParser(description="Mass Algorithm Converter")
    parser.add_argument("directory", help="Directory to process")
    args = parser.parse_args()
    
    root_dir = Path(args.directory)
    learn_root = Path("_learn")
    learn_root.mkdir(exist_ok=True)

    if not root_dir.exists():
        print(f"Directory {root_dir} does not exist.")
        sys.exit(1)

    py_files = []
    for root, dirs, files in os.walk(root_dir):
        # Filter directories
        dirs[:] = [d for d in dirs if d not in SKIP_DIRS and not d.startswith('.')]
        
        for file in files:
            if file.endswith(SOURCE_EXTENSION) and file != "__init__.py":
                py_files.append(Path(root) / file)

    print(f"Found {len(py_files)} Python files in {root_dir}")
    
    # Process files in parallel
    # Limit max workers to avoid overwhelming local LLM if it queues requests
    # Ollama usually handles one request at a time efficiently, maybe 2?
    # Let's stick to 1 file at a time (sequential files) but parallel languages inside process_file?
    # Actually, local LLM is the bottleneck. Parallel requests might just queue up.
    # Let's do sequential files to keep output readable and progress visible.
    
    for py_file in py_files:
        process_file(py_file, learn_root)

if __name__ == "__main__":
    main()
