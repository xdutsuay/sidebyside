import os
import sys

def check_files(start_dir):
    error_markers = [
        "Error: <urlopen error",
        "Connection refused",
        "404: Not Found",
        # Add other markers if needed
    ]
    
    errored_files = []

    for root, dirs, files in os.walk(start_dir):
        if ".git" in dirs:
            dirs.remove(".git")
        
        for file in files:
            if file.endswith(('.cpp', '.js', '.rs', '.go', '.py')):
                path = os.path.join(root, file)
                try:
                    with open(path, 'r', encoding='utf-8', errors='ignore') as f:
                        content = f.read()
                        # Check specifics
                        if any(marker in content for marker in error_markers):
                            errored_files.append(path)
                        # Optional: Check for very small files that should be larger (like 1 line error messages)
                        if len(content.splitlines()) <= 1 and "Error" in content:
                             if path not in errored_files:
                                 errored_files.append(path)

                except Exception as e:
                    print(f"Could not read {path}: {e}")

    return errored_files

if __name__ == "__main__":
    root_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__))) # Go up from /scripts/
    print(f"Scanning for errors in {root_dir}...")
    
    errors = check_files(root_dir)
    
    if errors:
        print(f"\nFound {len(errors)} potential error files:")
        for e in errors:
            print(f"- {e}")
        sys.exit(1)
    else:
        print("\nNo error markers found.")
        sys.exit(0)
