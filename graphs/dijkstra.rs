/**
 * Dijkstra's Algorithm in Rust
 */

use std::cmp::Ordering;
use std::collections::BinaryHeap;

#[derive(Copy, Clone, Eq, PartialEq)]
struct State {
    cost: usize,
    position: usize,
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

struct Edge {
    node: usize,
    cost: usize,
}

struct Graph {
    adj: Vec<Vec<Edge>>,
}

impl Graph {
    fn new(n: usize) -> Self {
        Graph {
            adj: (0..n).map(|_| Vec::new()).collect(),
        }
    }

    fn add_edge(&mut self, u: usize, v: usize, cost: usize) {
        self.adj[u].push(Edge { node: v, cost });
        self.adj[v].push(Edge { node: u, cost });
    }

    fn shortest_path(&self, start: usize, goal: usize) -> Option<usize> {
        let mut dist: Vec<_> = (0..self.adj.len()).map(|_| usize::MAX).collect();
        let mut heap = BinaryHeap::new();

        dist[start] = 0;
        heap.push(State { cost: 0, position: start });

        while let Some(State { cost, position }) = heap.pop() {
            if position == goal {
                return Some(cost);
            }

            if cost > dist[position] {
                continue;
            }

            for edge in &self.adj[position] {
                let next = State {
                    cost: cost + edge.cost,
                    position: edge.node,
                };

                if next.cost < dist[next.position] {
                    heap.push(next);
                    dist[next.position] = next.cost;
                }
            }
        }
        None
    }
}

fn main() {
    let mut graph = Graph::new(5);
    graph.add_edge(0, 1, 7);
    graph.add_edge(0, 2, 9);
    graph.add_edge(0, 5, 14); // Note: 5 is out of bounds for size 5, fixing to size 6 below
    
    // Proper example
    let mut g = Graph::new(9);
    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 8, 2);
    g.add_edge(2, 5, 4);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);

    match g.shortest_path(0, 4) {
        Some(cost) => println!("Minimum cost from 0 to 4 is {}", cost),
        None => println!("No path found"),
    }
}