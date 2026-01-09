/**
 * DFS implementation in JavaScript - FILL IN THE BLANKS
 */
class Graph {
    constructor() {
        this.adj = {};
    }

    addEdge(u, v) {
        if (!this.adj[u]) this.adj[u] = [];
        this.adj[u].push(v);
    }

    dfs(start) {
        let explored = new Set();
        let stack = [start];
        explored.add(start);

        while (stack.length > 0) {
            // Pop the last element
            let v = stack.____________();

            let neighbors = this.adj[v] || [];

            for (let i = neighbors.length - 1; i >= 0; i--) {
                let adj = neighbors[i];
                if (!explored.has(____________)) {
                    stack.push(adj);
                    explored.add(adj);
                }
            }
        }
        return explored;
    }
}