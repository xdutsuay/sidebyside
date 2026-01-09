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
        while self.sequence.len() < index {
            let next_val = self.sequence[self.sequence.len() - 1] + ____________;
            self.sequence.push(next_val);
        }
        self.sequence[..index].to_vec()
    }
}
