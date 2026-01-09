/**
 * Binary Search Tree implementation - FILL IN THE BLANKS
 */
class Node {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

class BinarySearchTree {
    constructor() { this.root = null; }

    insertNode(node, newNode) {
        if (newNode.value < node.value) {
            if (node.left === null) {
                node.left = newNode;
            } else {
                this.insertNode(node.left, newNode);
            }
        } else {
            if (node.right === null) {
                node.right = ____________; // Assign
            } else {
                this.insertNode(____________, newNode); // Recurse
            }
        }
    }
    // ...
}
