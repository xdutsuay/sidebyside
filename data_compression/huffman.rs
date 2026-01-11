/**
 * Huffman Coding in Rust
 */

use std::cmp::Ordering;
use std::collections::{BinaryHeap, HashMap};

#[derive(Debug, Eq, PartialEq)]
struct Node {
    freq: usize,
    char: Option<char>,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Ord for Node {
    fn cmp(&self, other: &Self) -> Ordering {
        other.freq.cmp(&self.freq)
    }
}

impl PartialOrd for Node {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

fn build_tree(text: &str) -> Option<Box<Node>> {
    let mut freq_map = HashMap::new();
    for c in text.chars() {
        *freq_map.entry(c).or_insert(0) += 1;
    }

    let mut heap = BinaryHeap::new();
    for (char, freq) in freq_map {
        heap.push(Box::new(Node {
            freq,
            char: Some(char),
            left: None,
            right: None,
        }));
    }

    while heap.len() > 1 {
        let left = heap.pop().unwrap();
        let right = heap.pop().unwrap();

        let parent = Box::new(Node {
            freq: left.freq + right.freq,
            char: None,
            left: Some(left),
            right: Some(right),
        });

        heap.push(parent);
    }

    heap.pop()
}

fn print_codes(node: &Option<Box<Node>>, str: String) {
    if let Some(n) = node {
        if let Some(c) = n.char {
            println!("{}: {}", c, str);
        } else {
            print_codes(&n.left, format!("{}0", str));
            print_codes(&n.right, format!("{}1", str));
        }
    }
}

fn main() {
    let text = "this is an example for huffman encoding";
    let root = build_tree(text);
    print_codes(&root, String::from(""));
}
