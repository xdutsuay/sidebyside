/**
 * Singly Linked List implementation in JavaScript - FILL IN THE BLANKS
 */
class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }

    insertHead(data) {
        let newNode = new Node(data);
        newNode.next = ____________;
        this.head = ____________;
    }

    insertTail(data) {
        let newNode = new Node(data);
        if (this.head === null) {
            this.head = ____________;
        } else {
            let current = this.head;
            while (current.next !== null) {
                current = current.next;
            }
            current.next = ____________;
        }
    }

    reverse() {
        let prev = null;
        let current = this.head;
        while (current !== null) {
            let nextNode = current.next;
            current.next = ____________; // Point backwards
            prev = ____________; // Advance prev
            current = ____________; // Advance current
        }
        this.head = prev;
    }
}
