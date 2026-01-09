#include <deque>
#include <iostream>
#include <stdexcept>

// Queue implementation using std::deque to support rotation efficiently
template <typename T> class Queue {
private:
  std::deque<T> entries;

public:
  void put(T item) { entries.push_back(item); }

  T get() {
    if (entries.empty()) {
      throw std::out_of_range("Queue is empty");
    }
    T item = entries.front();
    entries.pop_front();
    return item;
  }

  T get_front() const {
    if (entries.empty()) {
      throw std::out_of_range("Queue is empty");
    }
    return entries.front();
  }

  void rotate(int rotation) {
    if (entries.empty())
      return;
    for (int i = 0; i < rotation; ++i) {
      T item = entries.front();
      entries.pop_front();
      entries.push_back(item);
    }
  }

  bool isEmpty() const { return entries.empty(); }

  int size() const { return entries.size(); }
};

int main() {
  Queue<int> q;
  q.put(10);
  q.put(20);
  q.put(30);

  std::cout << "Front: " << q.get_front() << std::endl; // 10
  q.rotate(1);
  std::cout << "Front after rotation: " << q.get_front() << std::endl; // 20

  std::cout << "Get: " << q.get() << std::endl;   // 20
  std::cout << "Size: " << q.size() << std::endl; // 2

  return 0;
}
