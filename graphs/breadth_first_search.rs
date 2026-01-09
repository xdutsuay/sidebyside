use std::collections::{HashMap, HashSet, VecDeque};

/**
 * Graph struct implementation in Rust
 */
struct Graph {
    vertices: HashMap<i32, Vec<i32>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            vertices: HashMap::new(),
        }
    }

    /**
     * Adds an edge to the graph
     */
    fn add_edge(&mut self, from_vertex: i32, to_vertex: i32) {
        self.vertices.entry(from_vertex).or_insert(Vec::new()).push(to_vertex);
        self.vertices.entry(to_vertex).or_insert(Vec::new());
    }

    /**
     * Prints the graph
     */
    fn print_graph(&self) {
        for (vertex, edges) in &self.vertices {
            println!("{} : {:?}", vertex, edges);
        }
    }

    /**
     * Performs Breadth First Search
     */
    fn bfs(&self, start_vertex: i32) -> HashSet<i32> {
        let mut visited = HashSet::new();
        let mut queue = VecDeque::new();

        visited.insert(start_vertex);
        queue.push_back(start_vertex);

        while let Some(vertex) = queue.pop_front() {
            if let Some(neighbors) = self.vertices.get(&vertex) {
                for &neighbor in neighbors {
                    if !visited.contains(&neighbor) {
                        visited.insert(neighbor);
                        queue.push_back(neighbor);
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
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    g.print_graph();

    let result = g.bfs(2);
    let mut sorted_result: Vec<_> = result.into_iter().collect();
    sorted_result.sort();
    println!("BFS Result (starting from 2): {:?}", sorted_result);
}