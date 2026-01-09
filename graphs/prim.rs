/**
 * Prim's Algorithm in Rust
 */

const V: usize = 5;

fn min_key(key: &[i32], mst_set: &[bool]) -> usize {
    let mut min = i32::MAX;
    let mut min_index = 0;

    for v in 0..V {
        if !mst_set[v] && key[v] < min {
            min = key[v];
            min_index = v;
        }
    }
    min_index
}

fn print_mst(parent: &[i32], graph: &Vec<Vec<i32>>) {
    println!("Edge \tWeight");
    for i in 1..V {
        println!("{} - {} \t{}", parent[i], i, graph[i][parent[i] as usize]);
    }
}

fn prim_mst(graph: &Vec<Vec<i32>>) {
    let mut parent = vec![0; V];
    let mut key = vec![i32::MAX; V];
    let mut mst_set = vec![false; V];

    key[0] = 0;
    parent[0] = -1;

    for _ in 0..V - 1 {
        let u = min_key(&key, &mst_set);
        mst_set[u] = true;

        for v in 0..V {
            if graph[u][v] != 0 && !mst_set[v] && graph[u][v] < key[v] {
                parent[v] = u as i32;
                key[v] = graph[u][v];
            }
        }
    }

    print_mst(&parent, graph);
}

fn main() {
    /* Let us create the following graph
        2    3
    (0)--(1)--(2)
     |   / \   |
    6| 8/   \5 |7
     | /     \ |
    (3)-------(4)
          9          */
    let graph = vec![
        vec![0, 2, 0, 6, 0],
        vec![2, 0, 3, 8, 5],
        vec![0, 3, 0, 0, 7],
        vec![6, 8, 0, 0, 9],
        vec![0, 5, 7, 9, 0],
    ];

    prim_mst(&graph);
}