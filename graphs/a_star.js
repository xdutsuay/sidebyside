/**
 * A* Search in JavaScript
 */
const DIRECTIONS = [
    [-1, 0], // left
    [0, -1], // down
    [1, 0],  // right
    [0, 1]   // up
];

function search(grid, init, goal, cost, heuristic) {
    let rows = grid.length;
    let cols = grid[0].length;

    let closed = Array(rows).fill().map(() => Array(cols).fill(0));
    let action = Array(rows).fill().map(() => Array(cols).fill(0));

    closed[init[0]][init[1]] = 1;

    let x = init[0];
    let y = init[1];
    let g = 0;
    let f = g + heuristic[x][y];

    // Cell format: [f, g, x, y]
    let open = [[f, g, x, y]];

    let found = false;
    let resign = false;

    while (!found && !resign) {
        if (open.length === 0) {
            resign = true;
            console.log("Algorithm is unable to find solution");
            return { path: [], action: [] };
        } else {
            // Sort descending by f so sorting + popping is efficient
            open.sort((a, b) => b[0] - a[0]);
            let nextCell = open.pop();

            x = nextCell[2];
            y = nextCell[3];
            g = nextCell[1];

            if (x === goal[0] && y === goal[1]) {
                found = true;
            } else {
                for (let i = 0; i < DIRECTIONS.length; i++) {
                    let x2 = x + DIRECTIONS[i][0];
                    let y2 = y + DIRECTIONS[i][1];

                    if (x2 >= 0 && x2 < rows && y2 >= 0 && y2 < cols &&
                        closed[x2][y2] === 0 && grid[x2][y2] === 0) {

                        let g2 = g + cost;
                        let f2 = g2 + heuristic[x2][y2];
                        open.push([f2, g2, x2, y2]);
                        closed[x2][y2] = 1;
                        action[x2][y2] = i;
                    }
                }
            }
        }
    }

    let path = [];
    if (found) {
        x = goal[0];
        y = goal[1];
        let invpath = [[x, y]];

        while (x !== init[0] || y !== init[1]) {
            let x2 = x - DIRECTIONS[action[x][y]][0];
            let y2 = y - DIRECTIONS[action[x][y]][1];
            x = x2;
            y = y2;
            invpath.push([x, y]);
        }
        path = invpath.reverse();
    }

    return { path, action };
}

const grid = [
    [0, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 1, 0],
    [0, 0, 0, 0, 1, 0],
];
const init = [0, 0];
const goal = [grid.length - 1, grid[0].length - 1];
const cost = 1;
let heuristic = Array(grid.length).fill().map(() => Array(grid[0].length).fill(0));

for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[0].length; j++) {
        heuristic[i][j] = Math.abs(i - goal[0]) + Math.abs(j - goal[1]);
        if (grid[i][j] === 1) heuristic[i][j] = 99;
    }
}

const result = search(grid, init, goal, cost, heuristic);
console.log("Path:", JSON.stringify(result.path));