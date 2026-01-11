/**
 * Breadth First Search Algorithm in Rust
 */

use std::collections::{HashMap, HashSet, VecDeque};

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

    fn bfs(&self, s: i32) {
        let mut visited = HashSet::new();
        let mut queue = VecDeque::new();

        visited.insert(s);
        queue.push_back(s);

        while let Some(u) = queue.pop_front() {
            print!("{} ", u);

            if let Some(neighbors) = self.adj.get(&u) {
                for &v in neighbors {
                    if !visited.contains(&v) {
                        visited.insert(v);
                        queue.push_back(v);
                    }
                }
            }
        }
        println!();
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

    println!("Following is Breadth First Traversal (starting from vertex 2)");
    g.bfs(2);
}