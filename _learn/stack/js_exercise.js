/**
 * Stack implementation in JavaScript - FILL IN THE BLANKS
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
        // Add to end
        this.stack.____________(data);
    }

    pop() {
        if (this.stack.length === 0) {
            throw new Error("Stack Underflow");
        }
        // Remove from end
        return this.stack.____________();
    }

    peek() {
        if (this.stack.length === 0) {
            throw new Error("Stack Underflow");
        }
        // Return last element
        return this.stack[____________];
    }
}
