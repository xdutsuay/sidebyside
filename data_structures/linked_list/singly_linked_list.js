/**
 * Singly Linked List implementation in JavaScript
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
        this.size = 0;
    }

    isEmpty() {
        return this.head === null;
    }

    length() {
        return this.size;
    }

    insertHead(data) {
        let newNode = new Node(data);
        newNode.next = this.head;
        this.head = newNode;
        this.size++;
    }

    insertTail(data) {
        let newNode = new Node(data);
        if (this.head === null) {
            this.head = newNode;
        } else {
            let current = this.head;
            while (current.next !== null) {
                current = current.next;
            }
            current.next = newNode;
        }
        this.size++;
    }

    insertNth(index, data) {
        if (index < 0 || index > this.size) return;
        if (index === 0) {
            this.insertHead(data);
            return;
        }
        let newNode = new Node(data);
        let current = this.head;
        for (let i = 0; i < index - 1; i++) {
            current = current.next;
        }
        newNode.next = current.next;
        current.next = newNode;
        this.size++;
    }

    deleteHead() {
        if (this.head === null) return null;
        let data = this.head.data;
        this.head = this.head.next;
        this.size--;
        return data;
    }

    deleteTail() {
        if (this.head === null) return null;
        if (this.head.next === null) return this.deleteHead();

        let current = this.head;
        while (current.next.next !== null) {
            current = current.next;
        }
        let data = current.next.data;
        current.next = null;
        this.size--;
        return data;
    }

    reverse() {
        let prev = null;
        let current = this.head;
        while (current !== null) {
            let nextNode = current.next;
            current.next = prev;
            prev = current;
            current = nextNode;
        }
        this.head = prev;
    }

    printList() {
        let current = this.head;
        let result = [];
        while (current !== null) {
            result.push(current.data);
            current = current.next;
        }
        console.log(result.join(" -> "));
    }
}

const ll = new LinkedList();
ll.insertTail(1);
ll.insertTail(2);
ll.insertTail(3);
ll.printList();

ll.insertHead(0);
ll.printList();

ll.reverse();
ll.printList();

console.log("Deleted head:", ll.deleteHead());
ll.printList();
