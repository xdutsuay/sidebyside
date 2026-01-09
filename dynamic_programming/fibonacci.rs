pub struct Fibonacci {
    sequence: Vec<i32>,
}

impl Fibonacci {
    pub fn new() -> Self {
        Fibonacci {
            sequence: vec![0, 1],
        }
    }

    pub fn get(&mut self, index: usize) -> Vec<i32> {
        if index == 0 {
            return Vec::new();
        }
        
        while self.sequence.len() < index {
            let next_val = self.sequence[self.sequence.len() - 1] + self.sequence[self.sequence.len() - 2];
            self.sequence.push(next_val);
        }
        
        self.sequence[..index].to_vec()
    }
}

fn main() {
    let mut fib = Fibonacci::new();
    println!("{:?}", fib.get(10));
}
