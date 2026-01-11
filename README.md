<div align="center">
  <h1>Side-by-Side Algorithms</h1>
  <h3>Master Algorithms in C++, JS, Rust, & Go</h3>
  <p><em>A multi-language learning companion to TheAlgorithms/Python. Compare, Implement, and Learn.</em></p>
</div>

> [!IMPORTANT]
> **This is a specialized fork.** While the original [TheAlgorithms/Python](https://github.com/TheAlgorithms/Python) repository collects algorithms implemented in Python, **this repository** is dedicated to **converting** those algorithms into other languages (C++, JS, Rust, Go) side-by-side and generating **interactive exercises** to help you learn them.

## 🎯 Project Goal
This repository is an experiment in **Side-by-Side Learning**. We take classic algorithms (originally in Python) and:
1.  **Convert** them into **C++, JavaScript, Rust, and Go**.
2.  **Generate** "Fill in the Blanks" learning exercises for each.
3.  **Supervise** your learning using a **Local LLM** (Ollama) that runs entirely on your machine.

## 🏗 Structure
For each algorithm (e.g., `Bubble Sort`), you will find:
*   **Original**: `sorts/bubble_sort.py`
*   **Translations**:
    *   `sorts/bubble_sort.cpp`
    *   `sorts/bubble_sort.js`
    *   `sorts/bubble_sort.rs`
    *   `sorts/bubble_sort.go`
*   **Learning**: `_learn/bubble_sort/` containing exercises with missing logic for you to complete.

## 🤖 The Supervisor (`supervisor.py`)
This project includes a local AI tutor script: `scripts/supervisor.py`.
*   **What it does**: It reads your code (e.g., your attempt at `_learn/bubble_sort/cpp_exercise.cpp`), sends it to your local Ollama instance (e.g., LLaMA 3.2), and generates:
    *   A Rating (1-10)
    *   Key Concepts/Tags
    *   A Quiz Question
*   **Privacy**: Your code never leaves your machine.
*   **Usage**:
    ```bash
    python3 scripts/supervisor.py --file _learn/bubble_sort/cpp_exercise.cpp
    ```
*   **Logs**: Feedback is saved to `_learn/learning_log.md`.

## 🚀 Getting Started
1.  Ensure you have [Ollama](https://ollama.com/) installed and running.
2.  Pick an algorithm in `_learn/`.
3.  Fill in the blanks.
4.  Run the supervisor to check your work!

## 📚 Supported Algorithms (Progress)
We are actively converting algorithms. Here is the current progress:

### ✅ Batch 7: Sorting
-   **Insertion Sort**
-   **Selection Sort**
-   **Heap Sort**

### ✅ Batch 8: Strings
-   **Knuth-Morris-Pratt (KMP)**
-   **Rabin-Karp**
-   **Z-Function**

### ✅ Batch 9: Ciphers & Math
-   **Caesar Cipher**
-   **Vigenere Cipher**
-   **Euclidean GCD**
-   **Sieve of Eratosthenes**

### ✅ Batch 10: Backtracking & Search
-   **N-Queens**
-   **Sudoku Solver**
-   **Binary Search**
-   **Single Number**

### 🚧 Batch 11: Matrix & Linear Algebra (In Progress)
-   **Matrix Multiplication**
-   **Matrix Transposition**
-   **Strassen's Algorithm**
-   **Rotate Matrix**

---
*Forked from [TheAlgorithms/Python](https://github.com/TheAlgorithms/Python)*
