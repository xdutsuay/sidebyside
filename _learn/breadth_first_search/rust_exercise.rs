use std::collections::{HashMap, HashSet, VecDeque};

struct Graph {
    vertices: HashMap<i32, Vec<i32>>,
}

impl Graph {
    fn new() -> Self {
        Graph { vertices: HashMap::new() }
    }

    fn add_edge(&mut self, from_vertex: i32, to_vertex: i32) {
        self.vertices.entry(from_vertex).or_insert(Vec::new()).push(to_vertex);
    }

    fn bfs(&self, start_vertex: i32) -> HashSet<i32> {
        let mut visited = HashSet::new();
        let mut queue = VecDeque::new();

        visited.insert(start_vertex);
        queue.push_back(start_vertex);

        while let Some(vertex) = queue.____________() { // Dequeue
            if let Some(neighbors) = self.vertices.get(&vertex) {
                for &neighbor in neighbors {
                    if !visited.contains(&neighbor) {
                        visited.insert(neighbor);
                        queue.push_back(____________);
                    }
                }
            }
        }
        visited
    }
}

fn main() {
    let mut g = Graph::new();
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    println!("{:?}", g.bfs(0));
}
