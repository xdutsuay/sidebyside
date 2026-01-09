#[derive(Debug, Clone)]
struct Node<T> {
    data: T,
    next: Option<Box<Node<T>>>,
}

pub struct LinkedList<T> {
    head: Option<Box<Node<T>>>,
    size: usize,
}

impl<T: std::fmt::Debug + Clone> LinkedList<T> {
    pub fn new() -> Self {
        LinkedList { head: None, size: 0 }
    }

    pub fn is_empty(&self) -> bool {
        self.head.is_none()
    }

    pub fn len(&self) -> usize {
        self.size
    }

    pub fn insert_head(&mut self, data: T) {
        let new_node = Box::new(Node {
            data,
            next: self.head.take(),
        });
        self.head = Some(new_node);
        self.size += 1;
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
                current = current.next.as_mut().unwrap();
            }
            current.next = Some(new_node);
        }
        self.size += 1;
    }

    pub fn delete_head(&mut self) -> Option<T> {
        self.head.take().map(|node| {
            self.head = node.next;
            self.size -= 1;
            node.data
        })
    }
    
    pub fn reverse(&mut self) {
        let mut prev = None;
        let mut current = self.head.take();
        
        while let Some(mut node) = current {
            let next = node.next.take();
            node.next = prev;
            prev = Some(node);
            current = next;
        }
        self.head = prev;
    }

    pub fn print_list(&self) {
        let mut current = &self.head;
        while let Some(node) = current {
            print!("{:?} -> ", node.data);
            current = &node.next;
        }
        println!("None");
    }
}

fn main() {
    let mut ll = LinkedList::new();
    ll.insert_tail(1);
    ll.insert_tail(2);
    ll.insert_tail(3);
    ll.print_list();

    ll.insert_head(0);
    ll.print_list();
    
    ll.reverse();
    ll.print_list();
    
    println!("Deleted: {:?}", ll.delete_head());
    ll.print_list();
}
