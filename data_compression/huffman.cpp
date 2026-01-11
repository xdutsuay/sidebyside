/**
 * @file
 * @brief Huffman Coding Implementation
 * @details
 * Huffman coding is a lossless data compression algorithm. The idea is to
 * assign variable-length codes to input characters. Shortest codes are assigned
 * to the most frequent characters.
 */

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// A Huffman Tree node
struct MinHeapNode {
  char data;
  unsigned freq;
  MinHeapNode *left, *right;

  MinHeapNode(char data, unsigned freq) {
    this->left = this->right = NULL;
    this->data = data;
    this->freq = freq;
  }
};

// For comparison of two heap nodes (needed in min heap)
struct compare {
  bool operator()(MinHeapNode *l, MinHeapNode *r) {
    return (l->freq > r->freq);
  }
};

// Prints huffman codes from the root of Huffman Tree
void printCodes(struct MinHeapNode *root, string str) {
  if (!root)
    return;

  if (root->data != '$')
    cout << root->data << ": " << str << "\n";

  printCodes(root->left, str + "0");
  printCodes(root->right, str + "1");
}

// The main function that builds a Huffman Tree and print codes by traversing
// the built Huffman Tree
void HuffmanCodes(string text) {
  // Count frequencies
  unordered_map<char, int> freq;
  for (char c : text) {
    freq[c]++;
  }

  // Create a min heap & inserts all characters of data[]
  priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;

  for (auto pair : freq) {
    minHeap.push(new MinHeapNode(pair.first, pair.second));
  }

  // Iterate while size of heap doesn't become 1
  while (minHeap.size() != 1) {
    // Extract the two minimum freq items from min heap
    MinHeapNode *left = minHeap.top();
    minHeap.pop();

    MinHeapNode *right = minHeap.top();
    minHeap.pop();

    // Create a new internal node with frequency equal to the sum of the
    // two nodes frequencies. Make the two extracted node as left and right
    // children of this new node. Add this node to the min heap.
    // '$' is a special value for internal nodes, not used
    MinHeapNode *top = new MinHeapNode('$', left->freq + right->freq);
    top->left = left;
    top->right = right;

    minHeap.push(top);
  }

  // Print Huffman codes using the Huffman tree built above
  printCodes(minHeap.top(), "");
}

int main() {
  string text = "this is an example for huffman encoding";
  HuffmanCodes(text);
  return 0;
}
