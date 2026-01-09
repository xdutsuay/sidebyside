#include <iostream>
#include <vector>

class Fibonacci {
private:
  std::vector<int> sequence;

public:
  Fibonacci() {
    sequence.push_back(0);
    sequence.push_back(1);
  }

  std::vector<int> get(int index) {
    if (index <= 0)
      return {};

    while (sequence.size() < index) {
      // Calculate next: sum of last two
      int next = sequence.back() + ____________;
      sequence.push_back(next);
    }

    std::vector<int> result;
    for (int i = 0; i < index; ++i) {
      result.push_back(sequence[i]);
    }
    return result;
  }
};

int main() {
  Fibonacci fib;
  auto res = fib.get(10);
  return 0;
}
