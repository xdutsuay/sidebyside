/**
 * Breadth First Search Algorithm
 */

class Graph {
    constructor() {
        this.adj = new Map();
    }

    addEdge(v, w) {
        if (!this.adj.has(v)) {
            this.adj.set(v, []);
        }
        this.adj.get(v).push(w);
    }

    BFS(s) {
        let visited = new Set();
        let queue = [];

        visited.add(s);
        queue.push(s);

        while (queue.length > 0) {
            s = queue.shift();
            console.log(s + " ");

            let neighbors = this.adj.get(s);
            if (neighbors) {
                for (let i of neighbors) {
                    if (!visited.has(i)) {
                        visited.add(i);
                        queue.push(i);
                    }
                }
            }
        }
    }
}

// Driver Code
let g = new Graph();
g.addEdge(0, 1);
g.addEdge(0, 2);
g.addEdge(1, 2);
g.addEdge(2, 0);
g.addEdge(2, 3);
g.addEdge(3, 3);

console.log("Following is Breadth First Traversal (starting from vertex 2)");
g.BFS(2);