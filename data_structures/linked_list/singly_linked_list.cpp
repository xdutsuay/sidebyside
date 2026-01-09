#include <iostream>
#include <string>
#include <vector>

// Generic Node using templates
template <typename T> struct Node {
  T data;
  Node *next;

  Node(T val) : data(val), next(nullptr) {}
};

template <typename T> class LinkedList {
private:
  Node<T> *head;
  int size;

public:
  LinkedList() : head(nullptr), size(0) {}

  // Destructor to clean up memory
  ~LinkedList() {
    Node<T> *current = head;
    while (current != nullptr) {
      Node<T> *next = current->next;
      delete current;
      current = next;
    }
  }

  bool isEmpty() const { return head == nullptr; }

  int length() const { return size; }

  void insertHead(T data) {
    Node<T> *newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
    size++;
  }

  void insertTail(T data) {
    Node<T> *newNode = new Node<T>(data);
    if (head == nullptr) {
      head = newNode;
    } else {
      Node<T> *temp = head;
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
    size++;
  }

  void insertNth(int index, T data) {
    if (index < 0 || index > size) {
      std::cerr << "Index out of range" << std::endl;
      return;
    }
    if (index == 0) {
      insertHead(data);
      return;
    }
    Node<T> *newNode = new Node<T>(data);
    Node<T> *temp = head;
    for (int i = 0; i < index - 1; ++i) {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    size++;
  }

  T deleteHead() {
    if (head == nullptr) {
      throw std::runtime_error("List is empty");
    }
    Node<T> *temp = head;
    T data = temp->data;
    head = head->next;
    delete temp;
    size--;
    return data;
  }

  T deleteTail() {
    if (head == nullptr) {
      throw std::runtime_error("List is empty");
    }
    if (head->next == nullptr) {
      return deleteHead();
    }
    Node<T> *temp = head;
    while (temp->next->next != nullptr) {
      temp = temp->next;
    }
    Node<T> *toDelete = temp->next;
    T data = toDelete->data;
    temp->next = nullptr;
    delete toDelete;
    size--;
    return data;
  }

  void reverse() {
    Node<T> *prev = nullptr;
    Node<T> *current = head;
    while (current != nullptr) {
      Node<T> *nextNode = current->next;
      current->next = prev;
      prev = current;
      current = nextNode;
    }
    head = prev;
  }

  void printList() const {
    Node<T> *temp = head;
    while (temp != nullptr) {
      std::cout << temp->data;
      if (temp->next != nullptr)
        std::cout << " -> ";
      temp = temp->next;
    }
    std::cout << std::endl;
  }
};

int main() {
  LinkedList<int> ll;
  ll.insertTail(1);
  ll.insertTail(2);
  ll.insertTail(3);
  ll.printList(); // 1 -> 2 -> 3

  ll.insertHead(0);
  ll.printList(); // 0 -> 1 -> 2 -> 3

  ll.reverse();
  ll.printList(); // 3 -> 2 -> 1 -> 0

  std::cout << "Deleted head: " << ll.deleteHead() << std::endl;
  ll.printList(); // 2 -> 1 -> 0

  return 0;
}
