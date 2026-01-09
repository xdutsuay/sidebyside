#include <deque>
#include <iostream>
#include <stdexcept>

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
    entries.____________(); // Remove front
    return item;
  }

  void rotate(int rotation) {
    if (entries.empty())
      return;
    for (int i = 0; i < rotation; ++i) {
      // Move front to back
      T item = entries.front();
      entries.pop_front();
      entries.____________(item);
    }
  }
};
