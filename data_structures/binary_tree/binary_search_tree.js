/**
 * Binary Search Tree implementation in JavaScript
 */
class Node {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

class BinarySearchTree {
    constructor() {
        this.root = null;
    }

    insert(value) {
        const newNode = new Node(value);
        if (this.root === null) {
            this.root = newNode;
        } else {
            this.insertNode(this.root, newNode);
        }
    }

    insertNode(node, newNode) {
        if (newNode.value < node.value) {
            if (node.left === null) {
                node.left = newNode;
            } else {
                this.insertNode(node.left, newNode);
            }
        } else {
            if (node.right === null) {
                node.right = newNode;
            } else {
                this.insertNode(node.right, newNode);
            }
        }
    }

    search(node, value) {
        if (node === null) {
            return false;
        }
        if (value < node.value) {
            return this.search(node.left, value);
        } else if (value > node.value) {
            return this.search(node.right, value);
        } else {
            return true;
        }
    }

    remove(value) {
        this.root = this.removeNode(this.root, value);
    }

    removeNode(node, value) {
        if (node === null) {
            return null;
        }

        if (value < node.value) {
            node.left = this.removeNode(node.left, value);
            return node;
        } else if (value > node.value) {
            node.right = this.removeNode(node.right, value);
            return node;
        } else {
            // Node found

            // Case 1: No children
            if (node.left === null && node.right === null) {
                node = null;
                return node;
            }

            // Case 2: One child
            if (node.left === null) {
                node = node.right;
                return node;
            } else if (node.right === null) {
                node = node.left;
                return node;
            }

            // Case 3: Two children
            const aux = this.findMinNode(node.right);
            node.value = aux.value;
            node.right = this.removeNode(node.right, aux.value);
            return node;
        }
    }

    findMinNode(node) {
        if (node.left === null) {
            return node;
        } else {
            return this.findMinNode(node.left);
        }
    }

    inorder(node) {
        if (node !== null) {
            this.inorder(node.left);
            console.log(node.value);
            this.inorder(node.right);
        }
    }

    getRootNode() {
        return this.root;
    }
}

const bst = new BinarySearchTree();
bst.insert(15);
bst.insert(25);
bst.insert(10);
bst.insert(7);
bst.insert(22);
bst.insert(17);
bst.insert(13);
bst.insert(5);
bst.insert(9);
bst.insert(27);

bst.inorder(bst.getRootNode());
console.log("Search 22:", bst.search(bst.getRootNode(), 22));
bst.remove(5);
console.log("After removing 5:");
bst.inorder(bst.getRootNode());
