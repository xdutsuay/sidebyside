pub fn greatest_common_divisor_recursive(a: i32, b: i32) -> i32 {
    if a == 0 {
        return b.abs();
    }
    greatest_common_divisor_recursive(____________, ____________)
}

pub fn greatest_common_divisor_iterative(mut a: i32, mut b: i32) -> i32 {
    while b != 0 {
        let temp = ____________;
        b = ____________;
        a = temp;
    }
    a.abs()
}
