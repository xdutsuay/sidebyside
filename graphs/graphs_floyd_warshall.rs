/**
 * Floyd Warshall Algorithm in Rust
 */

const INF: i32 = 99999;

fn floyd_warshall(graph: &Vec<Vec<i32>>) {
    let v_count = graph.len();
    let mut dist = graph.clone();

    for k in 0..v_count {
        for i in 0..v_count {
            for j in 0..v_count {
                if dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j] {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    print_solution(&dist);
}

fn print_solution(dist: &Vec<Vec<i32>>) {
    println!("The following matrix shows the shortest distances between every pair of vertices");
    for row in dist {
        for &val in row {
            if val == INF {
                print!("INF     ");
            } else {
                print!("{}     ", val);
            }
        }
        println!();
    }
}

fn main() {
    /*
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3
    */
    let graph = vec![
        vec![0, 5, INF, 10],
        vec![INF, 0, 3, INF],
        vec![INF, INF, 0, 1],
        vec![INF, INF, INF, 0],
    ];

    floyd_warshall(&graph);
}