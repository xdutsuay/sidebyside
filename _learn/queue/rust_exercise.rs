use std::collections::VecDeque;

pub struct Queue<T> {
    entries: VecDeque<T>,
}

impl<T> Queue<T> {
    pub fn new() -> Self {
        Queue { entries: VecDeque::new() }
    }

    pub fn put(&mut self, item: T) {
        self.entries.push_back(item);
    }

    pub fn get(&mut self) -> Option<T> {
        // Remove front
        self.entries.____________()
    }

    pub fn rotate(&mut self, rotation: usize) {
        if self.entries.is_empty() { return; }
        for _ in 0..rotation {
            if let Some(item) = self.entries.____________() {
                self.entries.push_back(item);
            }
        }
    }
}
