use std::collections::{HashMap, HashSet};

struct Graph {
    adj: HashMap<String, Vec<String>>,
}

impl Graph {
    fn new() -> Self {
        Graph { adj: HashMap::new() }
    }

    fn add_edge(&mut self, u: &str, v: &str) {
        // Implementation hidden
    }

    fn dfs(&self, start: &str) -> HashSet<String> {
        let mut explored = HashSet::new();
        let mut stack = Vec::new();

        stack.push(start.to_string());
        explored.insert(start.to_string());

        while let Some(v) = stack.____________() { // Pop
            if let Some(neighbors) = self.adj.get(&v) {
                for neighbor in neighbors.iter().rev() {
                    if !explored.contains(neighbor) {
                        stack.push(neighbor.clone());
                        explored.insert(____________);
                    }
                }
            }
        }
        explored
    }
}
