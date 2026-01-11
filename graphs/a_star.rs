/**
 * A* Search Algorithm in Rust
 */

use std::cmp::Ordering;
use std::collections::BinaryHeap;

#[derive(Copy, Clone, Eq, PartialEq)]
struct State {
    cost: usize,
    position: (usize, usize),
}

impl Ord for State {
    fn cmp(&self, other: &Self) -> Ordering {
        other.cost.cmp(&self.cost)
            .then_with(|| self.position.cmp(&other.position))
    }
}

impl PartialOrd for State {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

fn heuristic(a: (usize, usize), b: (usize, usize)) -> usize {
    ((a.0 as isize - b.0 as isize).abs() + (a.1 as isize - b.1 as isize).abs()) as usize
}

fn a_star(grid: &Vec<Vec<i32>>, start: (usize, usize), goal: (usize, usize)) -> Option<usize> {
    let rows = grid.len();
    let cols = grid[0].len();

    let mut dist = vec![vec![usize::MAX; cols]; rows];
    let mut heap = BinaryHeap::new();

    dist[start.0][start.1] = 0;
    heap.push(State { cost: 0, position: start });

    while let Some(State { cost, position }) = heap.pop() {
        if position == goal {
            return Some(cost);
        }

        if cost > dist[position.0][position.1] + heuristic(position, goal) {
            continue;
        }

        let (r, c) = position;
        let moves = [(0, 1), (0, -1), (1, 0), (-1, 0)];

        for (dr, dc) in moves.iter() {
            let nr = r as isize + dr;
            let nc = c as isize + dc;

            if nr >= 0 && nr < rows as isize && nc >= 0 && nc < cols as isize {
                let nr = nr as usize;
                let nc = nc as usize;

                if grid[nr][nc] == 0 { // 0 is wall in this implementation
                     continue;
                }

                let next_cost = dist[r][c] + 1; // Assuming cost 1 to move

                if next_cost < dist[nr][nc] {
                    heap.push(State {
                        cost: next_cost + heuristic((nr, nc), goal),
                        position: (nr, nc),
                    });
                    dist[nr][nc] = next_cost;
                }
            }
        }
    }
    None
}

fn main() {
    // 1-Walkable, 0-Blocked
    let grid = vec![
        vec![1, 0, 1, 1, 1],
        vec![1, 1, 1, 0, 1],
        vec![1, 1, 1, 0, 1],
        vec![0, 0, 1, 0, 1],
        vec![1, 1, 1, 0, 1],
    ];

    let start = (0, 0);
    let goal = (4, 4);

    match a_star(&grid, start, goal) {
        Some(cost) => println!("Minimum cost: {}", cost),
        None => println!("No path found"),
    }
}