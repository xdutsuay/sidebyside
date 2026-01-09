#include <iostream>
#include <string>

// Node Structure
template <typename T> struct Node {
  T data;
  Node *next;
  Node(T val) : data(val), next(nullptr) {}
};

// Linked List
template <typename T> class LinkedList {
private:
  Node<T> *head;

public:
  LinkedList() : head(nullptr) {}

  void insertHead(T data) {
    Node<T> *newNode = new Node<T>(data);
    newNode->next = ____________;
    head = ____________;
  }

  void insertTail(T data) {
    Node<T> *newNode = new Node<T>(data);
    if (head == nullptr) {
      head = ____________;
    } else {
      Node<T> *temp = head;
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = ____________;
    }
  }

  void reverse() {
    Node<T> *prev = nullptr;
    Node<T> *current = head;
    while (current != nullptr) {
      Node<T> *nextNode = current->next;
      current->next = ____________;
      prev = ____________;
      current = ____________;
    }
    head = prev;
  }
};

int main() {
  LinkedList<int> ll;
  ll.insertHead(1);
  return 0;
}
