#[derive(Debug, Clone)]
struct Node<T> {
    data: T,
    next: Option<Box<Node<T>>>,
}

pub struct LinkedList<T> {
    head: Option<Box<Node<T>>>,
}

impl<T> LinkedList<T> {
    pub fn new() -> Self {
        LinkedList { head: None }
    }

    pub fn insert_head(&mut self, data: T) {
        let new_node = Box::new(Node {
            data,
            next: self.head.take(), // Take ownership of current head
        });
        self.head = Some(____________);
    }

    pub fn insert_tail(&mut self, data: T) {
        let new_node = Box::new(Node {
            data,
            next: None,
        });

        if self.head.is_none() {
            self.head = Some(new_node);
        } else {
            let mut current = self.head.as_mut().unwrap();
            while current.next.is_some() {
                // Navigate to end
                current = current.next.as_mut().unwrap();
            }
            current.next = Some(____________);
        }
    }
}
