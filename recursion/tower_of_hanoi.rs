/**
 * Tower of Hanoi Implementation in Rust
 */

fn move_disk(fp: char, tp: char) {
    println!("moving disk from {} to {}", fp, tp);
}

fn move_tower(height: i32, from_pole: char, to_pole: char, with_pole: char) {
    if height >= 1 {
        move_tower(height - 1, from_pole, with_pole, to_pole);
        move_disk(from_pole, to_pole);
        move_tower(height - 1, with_pole, to_pole, from_pole);
    }
}

fn main() {
    let height = 3;
    move_tower(height, 'A', 'B', 'C');
}
