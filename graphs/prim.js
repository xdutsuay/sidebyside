/**
 * Prim's Algorithm Implementation
 * Finds MST for a weighted undirected graph.
 */

const V = 5;

function minKey(key, mstSet) {
    let min = Number.MAX_SAFE_INTEGER;
    let min_index = -1;

    for (let v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

function printMST(parent, graph) {
    console.log("Edge \tWeight");
    for (let i = 1; i < V; i++) {
        console.log(parent[i] + " - " + i + " \t" + graph[i][parent[i]]);
    }
}

function primMST(graph) {
    const parent = new Array(V);
    const key = new Array(V);
    const mstSet = new Array(V);

    for (let i = 0; i < V; i++) {
        key[i] = Number.MAX_SAFE_INTEGER;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (let count = 0; count < V - 1; count++) {
        const u = minKey(key, mstSet);
        mstSet[u] = true;

        for (let v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

// Driver code
/* Let us create the following graph
    2    3
(0)--(1)--(2)
 |   / \   |
6| 8/   \5 |7
 | /     \ |
(3)-------(4)
      9          */
const graph = [
    [0, 2, 0, 6, 0],
    [2, 0, 3, 8, 5],
    [0, 3, 0, 0, 7],
    [6, 8, 0, 0, 9],
    [0, 5, 7, 9, 0]
];

primMST(graph);