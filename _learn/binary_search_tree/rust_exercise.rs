// Rust imports omitted

pub struct BinarySearchTree { ... }

impl BinarySearchTree {
    pub fn insert(&mut self, value: i32) {
        if let Some(ref mut node) = self.root {
            Self::insert_node(node, value);
        } else {
            self.root = Some(Box::new(Node::new(value)));
        }
    }

    fn insert_node(node: &mut Node, value: i32) {
        match value.cmp(&node.value) {
            Ordering::Less => {
                if let Some(ref mut left) = node.left {
                    Self::insert_node(left, value);
                } else {
                    node.left = Some(Box::new(Node::new(value)));
                }
            }
            Ordering::Greater => {
                if let Some(ref mut right) = node.right {
                    Self::insert_node(____________, value); // Recurse right
                } else {
                    node.right = Some(Box::new(Node::new(value)));
                }
            }
            Ordering::Equal => {} 
        }
    }
}
