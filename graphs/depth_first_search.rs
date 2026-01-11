/**
 * Depth First Search Algorithm in Rust
 */

use std::collections::{HashMap, HashSet};

struct Graph {
    adj: HashMap<i32, Vec<i32>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            adj: HashMap::new(),
        }
    }

    fn add_edge(&mut self, v: i32, w: i32) {
        self.adj.entry(v).or_insert(Vec::new()).push(w);
    }

    fn dfs(&self, v: i32, visited: &mut HashSet<i32>) {
        visited.insert(v);
        print!("{} ", v);

        if let Some(neighbors) = self.adj.get(&v) {
            for &next in neighbors {
                if !visited.contains(&next) {
                    self.dfs(next, visited);
                }
            }
        }
    }
}

fn main() {
    let mut g = Graph::new();
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    println!("Following is Depth First Traversal (starting from vertex 2)");
    let mut visited = HashSet::new();
    g.dfs(2, &mut visited);
    println!();
}