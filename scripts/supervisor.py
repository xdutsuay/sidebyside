import os
import sys
import json
import urllib.request
import urllib.error
import argparse
from datetime import datetime

# Configuration
OLLAMA_URL = "http://localhost:11434/api/generate"
MODEL_NAME = "llama3.2:latest"  # Fallback to phi3:mini if this fails? Let's default to user's available model.
LEARNING_LOG_PATH = "_learn/learning_log.md"

def get_available_models():
    try:
        url = "http://localhost:11434/api/tags"
        with urllib.request.urlopen(url) as response:
            data = json.loads(response.read().decode())
            return [m['name'] for m in data['models']]
    except Exception as e:
        print(f"Error checking models: {e}")
        return []

def query_ollama(model, prompt):
    data = {
        "model": model,
        "prompt": prompt,
        "stream": False
    }
    encoded_data = json.dumps(data).encode('utf-8')
    req = urllib.request.Request(OLLAMA_URL, data=encoded_data, headers={'Content-Type': 'application/json'})
    
    try:
        with urllib.request.urlopen(req) as response:
            result = json.loads(response.read().decode())
            return result.get('response', '')
    except urllib.error.URLError as e:
        return f"Error communicating with Ollama: {e}"

def generate_prompt(code_content, language, filename):
    return f"""
You are an expert coding tutor. I have written some {language} code in the file '{filename}'.
Here is the code:
```
{code_content}
```

Please provide:
1. A rating of this implementation on a scale of 1-10.
2. 3 comma-separated keywords/tags for this algorithm.
3. A short, conceptual "fill-in-the-blank" or multiple-choice quiz question related to this specific code/algorithm to test my understanding.

Format your response exactly like this:
**Rating:** <rating>/10
**Tags:** <tag1>, <tag2>, <tag3>
**Quiz:** <question>
**Feedback:** <short 1-2 sentence feedback>
"""

def main():
    parser = argparse.ArgumentParser(description='Supervisor Agent for Code Learning')
    parser.add_argument('--file', required=True, help='Path to the code file to review')
    parser.add_argument('--model', help='Ollama model to use', default=None)
    
    args = parser.parse_args()
    
    if not os.path.exists(args.file):
        print(f"File not found: {args.file}")
        sys.exit(1)
        
    # Model Selection
    available_models = get_available_models()
    if not available_models:
        print("Could not find any Ollama models. Is Ollama running?")
        sys.exit(1)
    
    selected_model = args.model
    if not selected_model:
        if "llama3.2:latest" in available_models:
            selected_model = "llama3.2:latest"
        elif "phi3:mini" in available_models:
            selected_model = "phi3:mini"
        else:
            selected_model = available_models[0]
            
    print(f"Using model: {selected_model}")
    print(f"Reviewing file: {args.file}...")

    with open(args.file, 'r') as f:
        code_content = f.read()
        
    # Guess language
    ext = os.path.splitext(args.file)[1]
    lang_map = {'.py': 'Python', '.cpp': 'C++', '.js': 'JavaScript', '.rs': 'Rust', '.go': 'Go'}
    language = lang_map.get(ext, 'Unknown')

    prompt = generate_prompt(code_content, language, args.file)
    response = query_ollama(selected_model, prompt)
    
    print("\n--- Supervisor Feedback ---")
    print(response)
    print("---------------------------\n")

    # Logging
    log_entry = f"""
## Review: {os.path.basename(args.file)} ({datetime.now().strftime('%Y-%m-%d %H:%M:%S')})
**Model:** `{selected_model}`
{response}
---
"""
    
    # Ensure directory exists
    os.makedirs(os.path.dirname(LEARNING_LOG_PATH), exist_ok=True)
    
    with open(LEARNING_LOG_PATH, "a") as log_file:
        log_file.write(log_entry)
        
    print(f"Feedback logged to {LEARNING_LOG_PATH}")

if __name__ == "__main__":
    main()
