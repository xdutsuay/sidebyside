/**
 * Huffman Coding Implementation
 */

class MinHeapNode {
    constructor(data, freq) {
        this.data = data;
        this.freq = freq;
        this.left = null;
        this.right = null;
    }
}

class PriorityQueue {
    constructor() {
        this.values = [];
    }

    enqueue(node) {
        this.values.push(node);
        this.values.sort((a, b) => a.freq - b.freq);
    }

    dequeue() {
        return this.values.shift();
    }

    size() {
        return this.values.length;
    }
}

function printCodes(root, str) {
    if (!root) return;

    if (root.data !== '$') {
        console.log(root.data + ": " + str);
    }

    printCodes(root.left, str + "0");
    printCodes(root.right, str + "1");
}

function HuffmanCodes(text) {
    let freq = {};
    for (let char of text) {
        freq[char] = (freq[char] || 0) + 1;
    }

    let minHeap = new PriorityQueue();

    for (let char in freq) {
        minHeap.enqueue(new MinHeapNode(char, freq[char]));
    }

    while (minHeap.size() > 1) {
        let left = minHeap.dequeue();
        let right = minHeap.dequeue();

        let top = new MinHeapNode('$', left.freq + right.freq);
        top.left = left;
        top.right = right;

        minHeap.enqueue(top);
    }

    printCodes(minHeap.dequeue(), "");
}

// Driver Code
const text = "this is an example for huffman encoding";
HuffmanCodes(text);
