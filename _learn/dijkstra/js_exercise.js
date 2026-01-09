/**
 * Dijkstra's Algorithm in JavaScript - FILL IN THE BLANKS
 */
class PriorityQueue {
    constructor() { this.list = []; }
    enqueue(element, priority) {
        this.list.push({ element, priority });
        this.list.sort((a, b) => a.priority - b.priority);
    }
    dequeue() { return this.list.shift(); }
    isEmpty() { return this.list.length === 0; }
}

class Graph {
    constructor() { this.adj = {}; }
    addEdge(u, v, weight) {
        if (!this.adj[u]) this.adj[u] = [];
        this.adj[u].push({ node: v, weight });
    }

    dijkstra(start, end) {
        let pq = new PriorityQueue();
        let visited = new Set();

        pq.enqueue(start, 0);

        while (!pq.isEmpty()) {
            let current = pq.dequeue();
            let u = current.element;
            let cost = current.priority;

            if (visited.has(u)) continue;
            visited.add(u);

            if (u === end) return ____________;

            if (this.adj[u]) {
                for (let neighbor of this.adj[u]) {
                    let v = neighbor.node;
                    let w = neighbor.weight;

                    if (!visited.has(v)) {
                        // Enqueue with accumulated cost
                        pq.enqueue(v, ____________ + w);
                    }
                }
            }
        }
        return -1;
    }
}