/**
 * Graph class implementation in JavaScript
 */
class Graph {
    constructor() {
        this.vertices = {};
    }

    /**
     * Adds an edge to the graph
     * @param {number} fromVertex 
     * @param {number} toVertex 
     */
    addEdge(fromVertex, toVertex) {
        if (!this.vertices[fromVertex]) {
            this.vertices[fromVertex] = [];
        }
        this.vertices[fromVertex].push(toVertex);

        // Ensure destination vertex exists
        if (!this.vertices[toVertex]) {
            this.vertices[toVertex] = [];
        }
    }

    /**
     * Prints the graph
     */
    printGraph() {
        for (let vertex in this.vertices) {
            console.log(vertex + " : " + this.vertices[vertex].join(" -> "));
        }
    }

    /**
     * Performs Breadth First Search
     * @param {number} startVertex 
     * @returns {Set} Set of visited vertices
     */
    bfs(startVertex) {
        let visited = new Set();
        let queue = [];

        visited.add(startVertex);
        queue.push(startVertex);

        while (queue.length > 0) {
            let vertex = queue.shift();

            let neighbors = this.vertices[vertex] || [];
            for (let neighbor of neighbors) {
                if (!visited.has(neighbor)) {
                    visited.add(neighbor);
                    queue.push(neighbor);
                }
            }
        }
        return visited;
    }
}

// Example usage
const g = new Graph();
g.addEdge(0, 1);
g.addEdge(0, 2);
g.addEdge(1, 2);
g.addEdge(2, 0);
g.addEdge(2, 3);
g.addEdge(3, 3);

g.printGraph();

const result = g.bfs(2);
console.log("BFS Result (starting from 2):", Array.from(result).sort());