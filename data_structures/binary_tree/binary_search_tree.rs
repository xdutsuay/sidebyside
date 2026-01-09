use std::cmp::Ordering;

#[derive(Debug)]
struct Node {
    value: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn new(value: i32) -> Self {
        Node {
            value,
            left: None,
            right: None,
        }
    }
}

pub struct BinarySearchTree {
    root: Option<Box<Node>>,
}

impl BinarySearchTree {
    pub fn new() -> Self {
        BinarySearchTree { root: None }
    }

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
                    Self::insert_node(right, value);
                } else {
                    node.right = Some(Box::new(Node::new(value)));
                }
            }
            Ordering::Equal => {} // Do nothing for duplicates
        }
    }

    pub fn search(&self, value: i32) -> bool {
        Self::search_node(&self.root, value)
    }

    fn search_node(node: &Option<Box<Node>>, value: i32) -> bool {
        match node {
            Some(n) => match value.cmp(&n.value) {
                Ordering::Less => Self::search_node(&n.left, value),
                Ordering::Greater => Self::search_node(&n.right, value),
                Ordering::Equal => true,
            },
            None => false,
        }
    }

    pub fn inorder(&self) {
        Self::inorder_node(&self.root);
        println!();
    }

    fn inorder_node(node: &Option<Box<Node>>) {
        if let Some(n) = node {
            Self::inorder_node(&n.left);
            print!("{} ", n.value);
            Self::inorder_node(&n.right);
        }
    }
}

fn main() {
    let mut bst = BinarySearchTree::new();
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    
    bst.inorder();
    println!("Search 40: {}", bst.search(40));
}
