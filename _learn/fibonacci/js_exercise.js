/**
 * Fibonacci sequence using Dynamic Programming - FILL IN THE BLANKS
 */
class Fibonacci {
    constructor() {
        this.sequence = [0, 1];
    }

    get(index) {
        if (index <= 0) return [];

        while (this.sequence.length < index) {
            const last = this.sequence[this.sequence.length - 1];
            const secondLast = this.sequence[____________];
            this.sequence.push(last + ____________);
        }
        return this.sequence.slice(0, index);
    }
}
