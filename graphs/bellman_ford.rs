/**
 * Bellman-Ford Algorithm in Rust
 */

#[derive(Debug, Clone)]
struct Edge {
    src: usize,
    dest: usize,
    weight: i32,
}

#[derive(Debug)]
struct Graph {
    v_count: usize,
    edges: Vec<Edge>,
}

impl Graph {
    fn new(v_count: usize) -> Self {
        Graph {
            v_count,
            edges: Vec::new(),
        }
    }

    fn add_edge(&mut self, src: usize, dest: usize, weight: i32) {
        self.edges.push(Edge { src, dest, weight });
    }
}

fn bellman_ford(graph: &Graph, src: usize) {
    let v = graph.v_count;
    let rank = i32::MAX;
    let mut dist = vec![rank; v];

    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times
    for _ in 1..v {
        for edge in &graph.edges {
            if dist[edge.src] != rank && dist[edge.src] + edge.weight < dist[edge.dest] {
                dist[edge.dest] = dist[edge.src] + edge.weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for edge in &graph.edges {
        if dist[edge.src] != rank && dist[edge.src] + edge.weight < dist[edge.dest] {
            println!("Graph contains negative weight cycle");
            return;
        }
    }

    print_arr(&dist);
}

fn print_arr(dist: &[i32]) {
    println!("Vertex   Distance from Source");
    for (i, d) in dist.iter().enumerate() {
        if *d == i32::MAX {
            println!("{}\t\tINF", i);
        } else {
            println!("{}\t\t{}", i, d);
        }
    }
}

fn main() {
    let v = 5;
    let mut graph = Graph::new(v);

    // [(0, 1, -1), (0, 2, 4), (1, 2, 3), (1, 3, 2), (1, 4, 2), (3, 2, 5), (3, 1, 1), (4, 3, -3)]
    graph.add_edge(0, 1, -1);
    graph.add_edge(0, 2, 4);
    graph.add_edge(1, 2, 3);
    graph.add_edge(1, 3, 2);
    graph.add_edge(1, 4, 2);
    graph.add_edge(3, 2, 5);
    graph.add_edge(3, 1, 1);
    graph.add_edge(4, 3, -3);

    bellman_ford(&graph, 0);
}