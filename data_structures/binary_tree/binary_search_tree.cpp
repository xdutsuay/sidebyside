#include <iostream>
#include <vector>

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
      return search(node->left, value);
    } else {
      return search(node->right, value);
    }
  }

  void inorder(Node *node) const {
    if (node != nullptr) {
      inorder(node->left);
      std::cout << node->value << " ";
      inorder(node->right);
    }
  }

  Node *findMin(Node *node) {
    while (node->left != nullptr)
      node = node->left;
    return node;
  }

  Node *remove(Node *node, int value) {
    if (node == nullptr)
      return nullptr;

    if (value < node->value) {
      node->left = remove(node->left, value);
    } else if (value > node->value) {
      node->right = remove(node->right, value);
    } else {
      // Node found

      // Case 1: No child
      if (node->left == nullptr && node->right == nullptr) {
        delete node;
        return nullptr;
      }
      // Case 2: One child
      else if (node->left == nullptr) {
        Node *temp = node->right;
        delete node;
        return temp;
      } else if (node->right == nullptr) {
        Node *temp = node->left;
        delete node;
        return temp;
      }
      // Case 3: Two children
      else {
        Node *temp = findMin(node->right);              // Inorder successor
        node->value = temp->value;                      // Copy value
        node->right = remove(node->right, temp->value); // Delete successor
      }
    }
    return node;
  }

public:
  BinarySearchTree() : root(nullptr) {}

  void insert(int value) { root = insert(root, value); }

  bool search(int value) const { return search(root, value); }

  void remove(int value) { root = remove(root, value); }

  void printInOrder() const {
    inorder(root);
    std::cout << std::endl;
  }
};

int main() {
  BinarySearchTree bst;
  bst.insert(50);
  bst.insert(30);
  bst.insert(20);
  bst.insert(40);
  bst.insert(70);
  bst.insert(60);
  bst.insert(80);

  bst.printInOrder(); // 20 30 40 50 60 70 80

  std::cout << "Search 40: " << bst.search(40) << std::endl; // 1
  std::cout << "Search 90: " << bst.search(90) << std::endl; // 0

  bst.remove(20);
  bst.printInOrder(); // 30 40 50 60 70 80

  return 0;
}
