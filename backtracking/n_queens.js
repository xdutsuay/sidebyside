/**
 * N-Queens Problem
 */

function isSafe(board, row, col) {
    const n = board.length;

    // Check col
    for (let i = 0; i < row; i++) {
        if (board[i][col] === 1) return false;
    }

    // Check upper left diagonal
    for (let i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] === 1) return false;
    }

    // Check upper right diagonal
    for (let i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] === 1) return false;
    }

    return true;
}

function printBoard(board) {
    for (const row of board) {
        console.log(row.map(cell => (cell ? "Q" : ".")).join(" "));
    }
    console.log("");
}

let solutions = 0;

function solve(board, row) {
    if (row >= board.length) {
        solutions++;
        printBoard(board);
        return;
    }

    for (let col = 0; col < board.length; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            solve(board, row + 1);
            board[row][col] = 0; // Backtrack
        }
    }
}

const n = 4;
const board = Array.from({ length: n }, () => Array(n).fill(0));
solve(board, 0);
console.log("Total solutions:", solutions);
