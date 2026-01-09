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
    stack.push_back(data);
  }

  T pop() {
    if (stack.empty()) {
      throw std::underflow_error("Stack Underflow");
    }
    T data = stack.back();
    stack.pop_back();
    return data;
  }

  T peek() const {
    if (stack.empty()) {
      throw std::underflow_error("Stack Underflow");
    }
    return stack.back();
  }

  bool isEmpty() const { return stack.empty(); }

  bool isFull() const { return stack.size() == limit; }

  int size() const { return stack.size(); }
};

int main() {
  Stack<int> s(5);
  s.push(1);
  s.push(2);
  s.push(3);

  std::cout << "Top: " << s.peek() << std::endl;
  std::cout << "Popped: " << s.pop() << std::endl;
  std::cout << "Size: " << s.size() << std::endl;

  return 0;
}
