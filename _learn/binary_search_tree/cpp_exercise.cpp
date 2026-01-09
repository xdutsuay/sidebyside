#include <iostream>

struct Node {
  int value;
  Node *left;
  Node *right;
  Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
  Node *root;

  Node *insert(Node *node, int value) {
    if (node == nullptr) {
      return new Node(value);
    }
    if (value < node->value) {
      node->left = insert(node->left, value);
    } else if (value > node->value) {
      node->right = insert(node->right, value);
    }
    return node;
  }

  bool search(Node *node, int value) const {
    if (node == nullptr)
      return false;
    if (node->value == value)
      return true;

    if (value < node->value) {
      return search(____________, value);
    } else {
      return search(____________, value);
    }
  }

public:
  BinarySearchTree() : root(nullptr) {}
  // ...
};
