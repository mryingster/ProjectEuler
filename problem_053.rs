// -*- compile-command: "rustc -o problem_053_rs problem_053.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn qualifies(n:usize, r:usize) -> bool {
    let mut n = n;
    let limit = 1000000;
    let mut nr = n-r;
    let mut answer = 1;

    while n > r {
        answer *= n;
        while nr > 1 && (answer % nr == 0 || answer > limit) {
            answer /= nr;
            nr -= 1;
        }

        if nr <= 1 && answer > limit {
            return true;
        }

        n -= 1;
    }

    return false
}


fn main() {
    println!("Project Euler - Problem 53:");
    println!("How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are greater than one-million?\n");

    let mut total = 0;

    for n in 23..101 {
        for r in 1..n {
            if qualifies(n, r) == true {
                total += 1;
            }
        }
    }

    println!("{}", total);
}
