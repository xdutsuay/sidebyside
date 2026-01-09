/**
 * Floyd Warshall Algorithm Implementation
 * Finds shortest distances between every pair of vertices.
 */

const INF = 99999;

function floydWarshall(graph) {
    const V = graph.length;
    // Create a deep copy of the graph to avoid modifying the original
    const dist = graph.map(row => [...row]);

    for (let k = 0; k < V; k++) {
        for (let i = 0; i < V; i++) {
            for (let j = 0; j < V; j++) {
                if (dist[i][k] !== INF && dist[k][j] !== INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist);
}

function printSolution(dist) {
    console.log("The following matrix shows the shortest distances between every pair of vertices");
    const V = dist.length;
    for (let i = 0; i < V; i++) {
        let row = "";
        for (let j = 0; j < V; j++) {
            if (dist[i][j] === INF) {
                row += "INF     ";
            } else {
                row += dist[i][j] + "     ";
            }
        }
        console.log(row);
    }
}

// Driver code
/*
        10
   (0)------->(3)
    |         /|\
  5 |          |
    |          | 1
   \|/         |
   (1)------->(2)
        3
*/
const graph = [
    [0, 5, INF, 10],
    [INF, 0, 3, INF],
    [INF, INF, 0, 1],
    [INF, INF, INF, 0]
];

floydWarshall(graph);