/**
 * BFS implementation in JavaScript - FILL IN THE BLANKS
 */
class Graph {
    constructor() {
        this.vertices = {};
    }

    addEdge(fromVertex, toVertex) {
        if (!this.vertices[fromVertex]) this.vertices[fromVertex] = [];
        this.vertices[fromVertex].push(toVertex);
    }

    bfs(startVertex) {
        let visited = new Set();
        let queue = [];

        visited.add(startVertex);
        queue.push(startVertex);

        while (queue.length > 0) {
            // Dequeue
            let vertex = queue.____________();

            let neighbors = this.vertices[vertex] || [];
            for (let neighbor of neighbors) {
                // If not visited, mark visited and enqueue
                if (!visited.has(____________)) {
                    visited.add(neighbor);
                    queue.push(neighbor);
                }
            }
        }
        return visited;
    }
}

const g = new Graph();
g.addEdge(0, 1);
g.addEdge(0, 2);
console.log(g.bfs(0));