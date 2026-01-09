/**
 * Fibonacci sequence using Dynamic Programming
 */
class Fibonacci {
    constructor() {
        this.sequence = [0, 1];
    }

    get(index) {
        if (index <= 0) return [];

        const currentLength = this.sequence.length;
        if (index > currentLength) {
            for (let i = currentLength; i < index; i++) {
                this.sequence.push(this.sequence[this.sequence.length - 1] + this.sequence[this.sequence.length - 2]);
            }
        }
        return this.sequence.slice(0, index);
    }
}

const fib = new Fibonacci();
console.log(fib.get(10));
