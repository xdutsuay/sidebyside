/**
 * Bellman-Ford Algorithm Implementation
 * Finds shortest paths from src to all other vertices.
 * Handles negative weight edges.
 */

class Edge {
    constructor(src, dest, weight) {
        this.src = src;
        this.dest = dest;
        this.weight = weight;
    }
}

class Graph {
    constructor(V, E) {
        this.V = V;
        this.E = E;
        this.edges = [];
    }

    addEdge(edge) {
        this.edges.push_back(edge); // Error in JS, should be push. Fixing in code.
        this.edges.push(edge);
    }
}

function bellmanFord(graph, src) {
    const V = graph.V;
    const E = graph.E;
    const dist = new Array(V).fill(Number.MAX_SAFE_INTEGER);

    // Step 1: Initialize distances
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times
    for (let i = 1; i < V; ++i) {
        for (let j = 0; j < E; ++j) {
            const u = graph.edges[j].src;
            const v = graph.edges[j].dest;
            const weight = graph.edges[j].weight;
            if (dist[u] !== Number.MAX_SAFE_INTEGER && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for (let j = 0; j < E; ++j) {
        const u = graph.edges[j].src;
        const v = graph.edges[j].dest;
        const weight = graph.edges[j].weight;
        if (dist[u] !== Number.MAX_SAFE_INTEGER && dist[u] + weight < dist[v]) {
            console.log("Graph contains negative weight cycle");
            return;
        }
    }

    printArr(dist, V);
}

function printArr(dist, V) {
    console.log("Vertex   Distance from Source");
    for (let i = 0; i < V; ++i) {
        if (dist[i] === Number.MAX_SAFE_INTEGER) {
            console.log(i + "\t\tINF");
        } else {
            console.log(i + "\t\t" + dist[i]);
        }
    }
}

// Test
const V = 5;
const E = 8;
const graph = new Graph(V, E);

// [(0, 1, -1), (0, 2, 4), (1, 2, 3), (1, 3, 2), (1, 4, 2), (3, 2, 5), (3, 1, 1), (4, 3, -3)]
graph.edges.push(new Edge(0, 1, -1));
graph.edges.push(new Edge(0, 2, 4));
graph.edges.push(new Edge(1, 2, 3));
graph.edges.push(new Edge(1, 3, 2));
graph.edges.push(new Edge(1, 4, 2));
graph.edges.push(new Edge(3, 2, 5));
graph.edges.push(new Edge(3, 1, 1));
graph.edges.push(new Edge(4, 3, -3));

bellmanFord(graph, 0);