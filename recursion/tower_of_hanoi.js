/**
 * Tower of Hanoi Implementation
 */

function moveDisk(fp, tp) {
    console.log(`moving disk from ${fp} to ${tp}`);
}

function moveTower(height, fromPole, toPole, withPole) {
    if (height >= 1) {
        moveTower(height - 1, fromPole, withPole, toPole);
        moveDisk(fromPole, toPole);
        moveTower(height - 1, withPole, toPole, fromPole);
    }
}

// Driver code
const height = 3;
moveTower(height, 'A', 'B', 'C');
