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
        self.stack.____________(data);
        Ok(())
    }

    pub fn pop(&mut self) -> Option<T> {
        self.stack.____________()
    }

    pub fn peek(&self) -> Option<&T> {
        self.stack.____________()
    }
}
