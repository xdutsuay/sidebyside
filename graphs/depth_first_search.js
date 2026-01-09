/**
 * DFS implementation in JavaScript
 */
class Graph {
    constructor() {
        this.adj = {};
    }

    addEdge(u, v) {
        if (!this.adj[u]) this.adj[u] = [];
        this.adj[u].push(v);
        if (!this.adj[v]) this.adj[v] = [];
    }

    dfs(start) {
        let explored = new Set();
        let stack = [start];
        explored.add(start);

        while (stack.length > 0) {
            let v = stack.pop();
            explored.add(v);

            let neighbors = this.adj[v] || [];
            // Python used reversed() to simulate standard order when popping
            // we can just iterate.
            for (let i = neighbors.length - 1; i >= 0; i--) {
                let adj = neighbors[i];
                if (!explored.has(adj)) {
                    stack.push(adj);
                }
            }
        }
        return explored;
    }
}

const g = new Graph();
g.addEdge("A", "B"); g.addEdge("A", "C"); g.addEdge("A", "D");
g.addEdge("B", "A"); g.addEdge("B", "D"); g.addEdge("B", "E");
g.addEdge("C", "A"); g.addEdge("C", "F");
g.addEdge("D", "B"); g.addEdge("D", "D");
g.addEdge("E", "B"); g.addEdge("E", "F");
g.addEdge("F", "C"); g.addEdge("F", "E"); g.addEdge("F", "G");
g.addEdge("G", "F");

const result = g.dfs("A");
console.log("DFS Result:", Array.from(result).sort());