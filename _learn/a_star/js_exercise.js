/**
 * A* Search in JavaScript - FILL IN THE BLANKS
 */
function search(grid, init, goal, cost, heuristic) {
    // ... setup ...
    let open = [[f, g, x, y]];

    while (!found && !resign) {
        if (open.length === 0) {
            resign = true;
        } else {
            // Sort by f descending
            open.sort((a, b) => b[0] - a[0]);
            let nextCell = open.pop();

            x = nextCell[2];
            y = nextCell[3];
            g = nextCell[1];

            if (x === goal[0] && y === goal[1]) {
                found = true;
            } else {
                for (let i = 0; i < DIRECTIONS.length; i++) {
                    // Check validity
                    if (/* valid and not closed */) {
                        let g2 = g + cost;
                        let f2 = g2 + ____________; // Add heuristic
                        open.push([f2, g2, x2, y2]);
                        closed[x2][y2] = 1;
                        action[x2][y2] = ____________; // Store direction index
                    }
                }
            }
        }
    }
    return { path, action };
}