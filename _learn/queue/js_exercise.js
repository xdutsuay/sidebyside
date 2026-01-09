/**
 * Queue implementation - FILL IN THE BLANKS
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
        // Remove and return front
        return this.entries.____________();
    }

    rotate(rotation) {
        for (let i = 0; i < rotation; i++) {
            // dequeue then enqueue
            this.put(this.____________());
        }
    }
}
