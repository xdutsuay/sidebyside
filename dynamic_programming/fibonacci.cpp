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

    int difference = index - (sequence.size());
    if (difference >= 0) {
      for (int i = 0; i <= difference; ++i) { // Calculate enough
        sequence.push_back(sequence.back() + sequence[sequence.size() - 2]);
      }
    }

    // Return sub-vector
    std::vector<int> result;
    for (int i = 0; i < index && i < sequence.size(); ++i) {
      result.push_back(sequence[i]);
    }
    return result;
  }
};

int main() {
  Fibonacci fib;
  std::vector<int> res = fib.get(10);
  for (int num : res)
    std::cout << num << " ";
  std::cout << std::endl;
  return 0;
}
