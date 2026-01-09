#include <iostream>
#include <stdexcept>
#include <vector>

// Generic Stack using vector
template <typename T> class Stack {
private:
  std::vector<T> stack;
  int limit;

public:
  Stack(int limit = 10) : limit(limit) {}

  void push(T data) {
    if (stack.size() >= limit) {
      throw std::overflow_error("Stack Overflow");
    }
    // Add to end
    stack.____________(data);
  }

  T pop() {
    if (stack.empty()) {
      throw std::underflow_error("Stack Underflow");
    }
    T data = stack.back();
    // Remove from end
    stack.____________();
    return data;
  }

  T peek() const {
    if (stack.empty()) {
      throw std::underflow_error("Stack Underflow");
    }
    return stack.____________(); // Get last element
  }
};
