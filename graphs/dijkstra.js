/**
 * Dijkstra's Algorithm in JavaScript
 */
class PriorityQueue {
    constructor() {
        this.list = [];
    }

    enqueue(element, priority) {
        this.list.push({ element, priority });
        this.list.sort((a, b) => a.priority - b.priority);
    }

    dequeue() {
        return this.list.shift();
    }

    isEmpty() {
        return this.list.length === 0;
    }
}

class Graph {
    constructor() {
        this.adj = {};
    }

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

            if (u === end) return cost;

            if (this.adj[u]) {
                for (let neighbor of this.adj[u]) {
                    let v = neighbor.node;
                    let w = neighbor.weight;

                    if (!visited.has(v)) {
                        pq.enqueue(v, cost + w);
                    }
                }
            }
        }
        return -1;
    }
}

const g = new Graph();
g.addEdge("A", "B", 2); g.addEdge("A", "C", 5);
g.addEdge("B", "A", 2); g.addEdge("B", "D", 3); g.addEdge("B", "E", 1); g.addEdge("B", "F", 1);
g.addEdge("C", "A", 5); g.addEdge("C", "F", 3);
g.addEdge("D", "B", 3);
g.addEdge("E", "B", 4); g.addEdge("E", "F", 3);
g.addEdge("F", "C", 3); g.addEdge("F", "E", 3);

console.log(g.dijkstra("E", "C"));