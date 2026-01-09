use std::collections::{HashMap, HashSet};

 struct Graph {
    adj: HashMap<String, Vec<String>>,
}

impl Graph {
    fn new() -> Self {
        Graph { adj: HashMap::new() }
    }

    fn add_edge(&mut self, u: &str, v: &str) {
        self.adj.entry(u.to_string()).or_insert(Vec::new()).push(v.to_string());
        self.adj.entry(v.to_string()).or_insert(Vec::new());
    }

    fn dfs(&self, start: &str) -> HashSet<String> {
        let mut explored = HashSet::new();
        let mut stack = Vec::new();

        stack.push(start.to_string());
        explored.insert(start.to_string());

        while let Some(v) = stack.pop() {
            // Note: In typical DFS you explore WHEN you pop. 
            // In the python code provided it has a slightly unique structure of pre-adding to explored set.
            // We follow the python logic:
            if !explored.contains(&v) {
                 explored.insert(v.clone());
            }

            if let Some(neighbors) = self.adj.get(&v) {
                // Reverse iteration
                for neighbor in neighbors.iter().rev() {
                    if !explored.contains(neighbor) {
                        stack.push(neighbor.clone());
                    }
                }
            }
        }
        explored
    }
}

fn main() {
    let mut g = Graph::new();
    g.add_edge("A", "B"); g.add_edge("A", "C"); g.add_edge("A", "D");
    g.add_edge("B", "A"); g.add_edge("B", "D"); g.add_edge("B", "E");
    g.add_edge("C", "A"); g.add_edge("C", "F");
    g.add_edge("D", "B"); g.add_edge("D", "D");
    g.add_edge("E", "B"); g.add_edge("E", "F");
    g.add_edge("F", "C"); g.add_edge("F", "E"); g.add_edge("F", "G");
    g.add_edge("G", "F");

    let result = g.dfs("A");
    let mut sorted_res: Vec<_> = result.iter().collect();
    sorted_res.sort();
    println!("DFS Result: {:?}", sorted_res);
}