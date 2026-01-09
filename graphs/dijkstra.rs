use std::collections::{HashMap, HashSet, BinaryHeap};
use std::cmp::Ordering;

#[derive(Clone, Eq, PartialEq)]
struct State {
    cost: i32,
    position: String,
}

// The priority queue depends on `Ord`.
// Explicitly implement the trait so the queue becomes a min-heap
// instead of a max-heap.
impl Ord for State {
    fn cmp(&self, other: &Self) -> Ordering {
        // Notice that the we flip the ordering on costs.
        // In case of a tie we compare positions - this step is necessary
        // to make implementations of `PartialEq` and `Ord` consistent.
        other.cost.cmp(&self.cost)
            .then_with(|| self.position.cmp(&other.position))
    }
}

// `PartialOrd` needs to be implemented as well.
impl PartialOrd for State {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

struct Graph {
    adj: HashMap<String, Vec<(String, i32)>>,
}

impl Graph {
    fn new() -> Self {
        Graph { adj: HashMap::new() }
    }

    fn add_edge(&mut self, u: &str, v: &str, weight: i32) {
        self.adj.entry(u.to_string()).or_insert(Vec::new()).push((v.to_string(), weight));
    }

    fn dijkstra(&self, start: &str, end: &str) -> i32 {
        let mut pq = BinaryHeap::new();
        let mut visited = HashSet::new();

        pq.push(State { cost: 0, position: start.to_string() });

        while let Some(State { cost, position }) = pq.pop() {
            if visited.contains(&position) {
                continue;
            }
            visited.insert(position.clone());

            if position == end {
                return cost;
            }

            if let Some(neighbors) = self.adj.get(&position) {
                for (neighbor, weight) in neighbors {
                    if !visited.contains(neighbor) {
                        pq.push(State {
                            cost: cost + weight,
                            position: neighbor.clone(),
                        });
                    }
                }
            }
        }
        -1
    }
}

fn main() {
    let mut g = Graph::new();
    g.add_edge("A", "B", 2); g.add_edge("A", "C", 5);
    g.add_edge("B", "A", 2); g.add_edge("B", "D", 3); g.add_edge("B", "E", 1); g.add_edge("B", "F", 1);
    g.add_edge("C", "A", 5); g.add_edge("C", "F", 3);
    g.add_edge("D", "B", 3);
    g.add_edge("E", "B", 4); g.add_edge("E", "F", 3);
    g.add_edge("F", "C", 3); g.add_edge("F", "E", 3);

    println!("{}", g.dijkstra("E", "C"));
}