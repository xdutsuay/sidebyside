/**
 * Queue implementation in JavaScript
 */
class Queue {
    constructor() {
        this.entries = [];
    }

    put(item) {
        this.entries.push(item);
    }

    get() {
        if (this.entries.length === 0) {
            throw new Error("Queue is empty");
        }
        return this.entries.shift();
    }

    getFront() {
        if (this.entries.length === 0) {
            throw new Error("Queue is empty");
        }
        return this.entries[0];
    }

    rotate(rotation) {
        for (let i = 0; i < rotation; i++) {
            this.put(this.get());
        }
    }

    size() {
        return this.entries.length;
    }

    isEmpty() {
        return this.entries.length === 0;
    }
}

const q = new Queue();
q.put(10);
q.put(20);
q.put(30);
console.log("Front:", q.getFront());
q.rotate(1);
console.log("Front after rotation:", q.getFront());
console.log("Get:", q.get());
