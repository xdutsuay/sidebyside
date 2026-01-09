#[derive(Debug)]
pub struct Stack<T> {
    stack: Vec<T>,
    limit: usize,
}

impl<T> Stack<T> {
    pub fn new(limit: usize) -> Self {
        Stack {
            stack: Vec::new(),
            limit,
        }
    }

    pub fn push(&mut self, data: T) -> Result<(), &'static str> {
        if self.stack.len() >= self.limit {
            return Err("Stack Overflow");
        }
        self.stack.push(data);
        Ok(())
    }

    pub fn pop(&mut self) -> Option<T> {
        self.stack.pop()
    }

    pub fn peek(&self) -> Option<&T> {
        self.stack.last()
    }

    pub fn is_empty(&self) -> bool {
        self.stack.is_empty()
    }

    pub fn is_full(&self) -> bool {
        self.stack.len() == self.limit
    }

    pub fn size(&self) -> usize {
        self.stack.len()
    }
}

fn main() {
    let mut s = Stack::new(5);
    s.push(1).unwrap();
    s.push(2).unwrap();
    s.push(3).unwrap();

    println!("Top: {:?}", s.peek());
    println!("Popped: {:?}", s.pop());
    println!("Size: {}", s.size());
}
