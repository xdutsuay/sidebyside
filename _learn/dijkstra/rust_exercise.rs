// Rust imports omitted for brevity

struct Graph { /* ... */ }

impl Graph {
    fn dijkstra(&self, start: &str, end: &str) -> i32 {
        let mut pq = BinaryHeap::new();
        let mut visited = HashSet::new();

        pq.push(State { cost: 0, position: start.to_string() });

        while let Some(State { cost, position }) = pq.pop() {
            if visited.contains(&position) {
                continue;
            }
            visited.insert(____________);

            if position == end {
                return cost;
            }

            if let Some(neighbors) = self.adj.get(&position) {
                for (neighbor, weight) in neighbors {
                    if !visited.contains(neighbor) {
                        pq.push(State {
                            cost: ____________,
                            position: neighbor.clone(),
                        });
                    }
                }
            }
        }
        -1
    }
}
