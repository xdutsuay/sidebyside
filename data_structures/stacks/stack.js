/**
 * Stack implementation in JavaScript
 */
class Stack {
    constructor(limit = 10) {
        this.stack = [];
        this.limit = limit;
    }

    push(data) {
        if (this.stack.length >= this.limit) {
            throw new Error("Stack Overflow");
        }
        this.stack.push(data);
    }

    pop() {
        if (this.stack.length === 0) {
            throw new Error("Stack Underflow");
        }
        return this.stack.pop();
    }

    peek() {
        if (this.stack.length === 0) {
            throw new Error("Stack Underflow");
        }
        return this.stack[this.stack.length - 1];
    }

    isEmpty() {
        return this.stack.length === 0;
    }

    isFull() {
        return this.stack.length === this.limit;
    }

    size() {
        return this.stack.length;
    }
}

const s = new Stack(5);
s.push(1);
s.push(2);
s.push(3);
console.log("Top:", s.peek());
console.log("Popped:", s.pop());
console.log("Size:", s.size());
