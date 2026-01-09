pub fn greatest_common_divisor_recursive(a: i32, b: i32) -> i32 {
    if a == 0 {
        return b.abs();
    }
    greatest_common_divisor_recursive(b % a, a)
}

pub fn greatest_common_divisor_iterative(mut a: i32, mut b: i32) -> i32 {
    while b != 0 {
        let temp = b;
        b = a % b;
        a = temp;
    }
    a.abs()
}

fn main() {
    let a = 24;
    let b = 40;
    println!("GCD Recursive ({}, {}) = {}", a, b, greatest_common_divisor_recursive(a, b));
    println!("GCD Iterative ({}, {}) = {}", a, b, greatest_common_divisor_iterative(a, b));
}
