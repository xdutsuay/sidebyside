/**
 * A* Search Algorithm
 */

class Node {
    constructor(x, y, parent = null) {
        this.x = x;
        this.y = y;
        this.parent = parent;
        this.g = 0;
        this.h = 0;
        this.f = 0;
    }
}

function aStar(grid, start, end) {
    let openList = [];
    let closedList = [];

    openList.push(start);

    while (openList.length > 0) {
        let lowInd = 0;
        for (let i = 0; i < openList.length; i++) {
            if (openList[i].f < openList[lowInd].f) {
                lowInd = i;
            }
        }

        let currentNode = openList[lowInd];

        if (currentNode.x === end.x && currentNode.y === end.y) {
            let curr = currentNode;
            let ret = [];
            while (curr.parent) {
                ret.push([curr.x, curr.y]);
                curr = curr.parent;
            }
            ret.push([curr.x, curr.y]);
            return ret.reverse();
        }

        openList.splice(lowInd, 1);
        closedList.push(currentNode);

        let neighbors = [];
        let x = currentNode.x;
        let y = currentNode.y;

        if (grid[x - 1] && grid[x - 1][y]) neighbors.push(new Node(x - 1, y, currentNode));
        if (grid[x + 1] && grid[x + 1][y]) neighbors.push(new Node(x + 1, y, currentNode));
        if (grid[x][y - 1] && grid[x][y - 1]) neighbors.push(new Node(x, y - 1, currentNode));
        if (grid[x][y + 1] && grid[x][y + 1]) neighbors.push(new Node(x, y + 1, currentNode));

        for (let i = 0; i < neighbors.length; i++) {
            let neighbor = neighbors[i];

            if (closedList.find(n => n.x === neighbor.x && n.y === neighbor.y) || grid[neighbor.x][neighbor.y] === 0) {
                continue;
            }

            let gScore = currentNode.g + 1;
            let gScoreIsBest = false;

            if (!openList.find(n => n.x === neighbor.x && n.y === neighbor.y)) {
                gScoreIsBest = true;
                neighbor.h = Math.abs(neighbor.x - end.x) + Math.abs(neighbor.y - end.y);
                openList.push(neighbor);
            } else if (gScore < neighbor.g) {
                gScoreIsBest = true;
            }

            if (gScoreIsBest) {
                neighbor.parent = currentNode;
                neighbor.g = gScore;
                neighbor.f = neighbor.g + neighbor.h;
            }
        }
    }
    return [];
}

// Driver Code
// 1 = Walkable, 0 = Wall
let grid = [
    [1, 0, 1, 1, 1],
    [1, 1, 1, 0, 1],
    [1, 1, 1, 0, 1],
    [0, 0, 1, 0, 1],
    [1, 1, 1, 0, 1]
];

let startNode = new Node(0, 0);
let endNode = new Node(4, 4);

let path = aStar(grid, startNode, endNode);
console.log("Path:", path);