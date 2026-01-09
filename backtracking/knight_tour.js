/**
 * Knight's Tour Algorithm (Backtracking)
 */

function solveKT(N) {
    const board = Array.from({ length: N }, () => Array(N).fill(-1));

    const xMove = [2, 1, -1, -2, -2, -1, 1, 2];
    const yMove = [1, 2, 2, 1, -1, -2, -2, -1];

    board[0][0] = 0;

    if (!solveKTUtil(0, 0, 1, board, xMove, yMove, N)) {
        console.log("Solution does not exist");
        return false;
    } else {
        printSolution(board);
    }
    return true;
}

function solveKTUtil(x, y, movei, board, xMove, yMove, N) {
    if (movei === N * N) return true;

    for (let k = 0; k < 8; k++) {
        const next_x = x + xMove[k];
        const next_y = y + yMove[k];

        if (isValid(next_x, next_y, N, board)) {
            board[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, board, xMove, yMove, N)) {
                return true;
            } else {
                board[next_x][next_y] = -1; // backtracking
            }
        }
    }
    return false;
}

function isValid(x, y, N, board) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] === -1);
}

function printSolution(board) {
    for (let i = 0; i < board.length; i++) {
        console.log(board[i].map(x => String(x).padStart(3, ' ')).join(' '));
    }
}

// Driver Code
solveKT(5);
