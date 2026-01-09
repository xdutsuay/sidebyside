use std::cmp::Ordering;

#[derive(Clone, Eq, PartialEq)]
struct Node {
    f: i32,
    g: i32,
    x: usize,
    y: usize,
}

// Implement Ord for sorting in BinaryHeap or Vec sorting
impl Ord for Node {
    fn cmp(&self, other: &Self) -> Ordering {
        // We want min f. 
        // If using Vec sort: sort ascending f.
        other.f.cmp(&self.f) // for max heap to behave like min heap usually, but here python uses list sort.
    }
}

impl PartialOrd for Node {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

const DIRECTIONS: [[i32; 2]; 4] = [[-1, 0], [0, -1], [1, 0], [0, 1]];

fn search(
    grid: &Vec<Vec<i32>>,
    init: [usize; 2],
    goal: [usize; 2],
    cost: i32,
    heuristic: &Vec<Vec<i32>>,
) -> (Vec<[usize; 2]>, Vec<Vec<usize>>) {
    let rows = grid.len();
    let cols = grid[0].len();
    
    let mut closed = vec![vec![0; cols]; rows];
    let mut action = vec![vec![0; cols]; rows];
    
    closed[init[0]][init[1]] = 1;
    
    let mut x = init[0];
    let mut y = init[1];
    let mut g = 0;
    let f = g + heuristic[x][y];
    
    let mut open = Vec::new();
    open.push(Node { f, g, x, y });
    
    let mut found = false;
    let mut resign = false;
    
    while !found && !resign {
        if open.is_empty() {
            resign = true;
            println!("Algorithm is unable to find solution");
            return (Vec::new(), Vec::new());
        } else {
            // Sort descending by f 
            open.sort_by(|a, b| b.f.cmp(&a.f));
            let next_cell = open.pop().unwrap();
            
            x = next_cell.x;
            y = next_cell.y;
            g = next_cell.g;
            
            if x == goal[0] && y == goal[1] {
                found = true;
            } else {
                for i in 0..4 {
                    let x2_i = x as i32 + DIRECTIONS[i][0];
                    let y2_i = y as i32 + DIRECTIONS[i][1];
                    
                    if x2_i >= 0 && x2_i < rows as i32 && y2_i >= 0 && y2_i < cols as i32 {
                        let x2 = x2_i as usize;
                        let y2 = y2_i as usize;
                        
                        if closed[x2][y2] == 0 && grid[x2][y2] == 0 {
                            let g2 = g + cost;
                            let f2 = g2 + heuristic[x2][y2];
                            open.push(Node { f: f2, g: g2, x: x2, y: y2 });
                            closed[x2][y2] = 1;
                            action[x2][y2] = i;
                        }
                    }
                }
            }
        }
    }
    
    let mut path = Vec::new();
    if found {
        x = goal[0];
        y = goal[1];
        path.push([x, y]);
        
        while x != init[0] || y != init[1] {
            let x2 = x as i32 - DIRECTIONS[action[x][y]][0];
            let y2 = y as i32 - DIRECTIONS[action[x][y]][1];
            x = x2 as usize;
            y = y2 as usize;
            path.push([x, y]);
        }
        path.reverse();
    }
    (path, action)
}

fn main() {
    let grid = vec![
        vec![0, 1, 0, 0, 0, 0],
        vec![0, 1, 0, 0, 0, 0],
        vec![0, 1, 0, 0, 0, 0],
        vec![0, 1, 0, 0, 1, 0],
        vec![0, 0, 0, 0, 1, 0],
    ];
    let init = [0, 0];
    let goal = [grid.len() - 1, grid[0].len() - 1];
    let cost = 1;
    
    let mut heuristic = vec![vec![0; grid[0].len()]; grid.len()];
    for i in 0..grid.len() {
        for j in 0..grid[0].len() {
            heuristic[i][j] = ((i as i32 - goal[0] as i32).abs() + (j as i32 - goal[1] as i32).abs());
            if grid[i][j] == 1 { heuristic[i][j] = 99; }
        }
    }

    let (path, _) = search(&grid, init, goal, cost, &heuristic);
    println!("Path: {:?}", path);
}