use std::collections::VecDeque;

#[derive(Debug)]
pub struct Queue<T> {
    entries: VecDeque<T>,
}

impl<T> Queue<T> {
    pub fn new() -> Self {
        Queue {
            entries: VecDeque::new(),
        }
    }

    pub fn put(&mut self, item: T) {
        self.entries.push_back(item);
    }

    pub fn get(&mut self) -> Option<T> {
        self.entries.pop_front()
    }

    pub fn get_front(&self) -> Option<&T> {
        self.entries.front()
    }

    pub fn rotate(&mut self, rotation: usize) {
        if self.entries.is_empty() {
            return;
        }
        for _ in 0..rotation {
            if let Some(item) = self.entries.pop_front() {
                self.entries.push_back(item);
            }
        }
    }

    pub fn len(&self) -> usize {
        self.entries.len()
    }

    pub fn is_empty(&self) -> bool {
        self.entries.is_empty()
    }
}

fn main() {
    let mut q = Queue::new();
    q.put(10);
    q.put(20);
    q.put(30);
    
    println!("Front: {:?}", q.get_front());
    q.rotate(1);
    println!("Front after rotation: {:?}", q.get_front());
    println!("Get: {:?}", q.get());
}
