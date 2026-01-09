// Bi-directional Dijkstra's algorithm.

/// Bi-directional Dijkstra's algorithm implementation.
///
/// Returns the shortest distance from source to destination in an undirected graph.
///
/// # Panics
///
/// If the destination is not reachable, it returns -1.
pub fn bi_directional_dij(source: &str, destination: &str, 
                         forward_graph: &HashMap<String, Vec<(String, i32)>>, 
                         backward_graph: &HashMap<String, Vec<(String, i32)>>) -> Option<i32> {
    let mut forward_distances = HashMap::new();
    let mut backward_distances = HashMap::new();
    let mut forward_parents = HashMap::new();
    let mut backward_parents = HashMap::new();
    let mut forward_queue = BinaryHeap::new();
    let mut backward_queue = BinaryHeap::new();

    // Initialize distances and parents for source node
    forward_distances.insert(source.to_string(), 0);
    forward_parents.insert(source.to_string(), None);
    forward_queue.push((0, source.to_string()));

    // Initialize distances and parents for destination node
    backward_distances.insert(destination.to_string(), 0);
    backward_parents.insert(destination.to_string(), None);
    backward_queue.push((0, destination.to_string()));

    let mut shortest_distance = Some(0);

    while !forward_queue.is_empty() && !backward_queue.is_empty() {
        // Get the next node with the smallest distance from forward graph
        if let Some((distance, node)) = forward_queue.pop() {
            for (neighbor, cost) in &forward_graph[node] {
                match backward_graph.get(neighbor) {
                    Some(neighbors) => {
                        let new_distance = distance + cost;
                        if new_distance < backward_distances[neighbor] {
                            backward_distances.insert(*neighbor, new_distance);
                            backward_parents.insert(*neighbor, node.to_string());
                            backward_queue.push((new_distance, *neighbor));
                        }
                    },
                    None => {}
                };
            }
        }

        // Get the next node with the smallest distance from backward graph
        if let Some((distance, node)) = backward_queue.pop() {
            for (neighbor, cost) in &backward_graph[node] {
                match forward_graph.get(neighbor) {
                    Some(neighbors) => {
                        let new_distance = distance + cost;
                        if new_distance < forward_distances[neighbor] {
                            forward_distances.insert(*neighbor, new_distance);
                            forward_parents.insert(*neighbor, node.to_string());
                            forward_queue.push((new_distance, *neighbor));
                        }
                    },
                    None => {}
                };
            }
        }

        // Check if we have found the shortest path
        if let Some(distance) = shortest_distance {
            if distance < shortest_distance.unwrap() {
                shortest_distance = Some(distance);
            } else if distance == shortest_distance.unwrap() {
                return None;
            }
        }
    }

    // If destination is reachable, return its distance; otherwise, return -1.
    match forward_distances.get(destination) {
        Some(distance) => Some(*distance),
        None => None,
    }
}

fn main() {
    let forward_graph = HashMap::from([
        ("B".to_string(), vec![("C".to_string(), 1)]),
        ("C".to_string(), vec!["D".to_string(), 1]),
        ("D".to_string(), vec!["F".to_string(), 1]),
        ("E".to_string(), vec!["B".to_string(), "G".to_string(), 2]),
        ("F".to_string(), vec![]),
        ("G".to_string(), vec!["F".to_string(), 1]),
    ]);

    let backward_graph = HashMap::from([
        ("B".to_string(), vec!["E".to_string(), 1]),
        ("C".to_string(), vec!["B".to_string(), 1]),
        ("D".to_string(), vec!["C".to_string(), 1]),
        ("F".to_string(), vec!["D".to_string(), "G".to_string(), 1]),
        ("E".to_string(), vec![None, std::i32::MAX]),
        ("G".to_string(), vec!["E".to_string(), 2]),
    ]);

    match bi_directional_dij("B", "F", &forward_graph, &backward_graph) {
        Some(distance) => println!("The shortest distance is: {}", distance),
        None => println!("Destination F is not reachable from source B"),
    }
}