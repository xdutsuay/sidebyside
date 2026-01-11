/**
 * Depth First Search Algorithm
 */

class Graph {
    constructor() {
        this.adj = new Map();
        this.visited = new Set();
    }

    addEdge(v, w) {
        if (!this.adj.has(v)) {
            this.adj.set(v, []);
        }
        this.adj.get(v).push(w);
    }

    DFS(v) {
        this.visited.add(v);
        console.log(v + " ");

        let neighbors = this.adj.get(v);
        if (neighbors) {
            for (let i of neighbors) {
                if (!this.visited.has(i)) {
                    this.DFS(i);
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

console.log("Following is Depth First Traversal (starting from vertex 2)");
g.DFS(2);