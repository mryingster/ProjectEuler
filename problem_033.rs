// -*- compile-command: "rustc -o problem_033_rs problem_033.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn reduce(mut f: [usize; 2]) -> [usize; 2] {
    let mut d = 2;

    while d <= f[0] {
        while f[0] % d == 0 && f[1] % d == 0 {
            f[0] /= d;
            f[1] /= d;
        }
        d += 1;
    }

    return f;
}

fn unorthodox(f: [usize; 2]) -> bool {
    // Numerator 2nd digit == denominator 1st digit
    if f[0]%10 == f[1]/10 {

        // Cancel unorthodoxly
        let c = [f[0]/10, f[1]%10];

        // See if fractions are the same by reducing them both
        if reduce(f) == reduce(c) {
            //println!("{}/{} = {}/{}", f[0], f[1], c[0], c[1]);
            return true;
        }
    }

    return false;
}

fn main() {
    println!("Project Euler - Problem 33:");
    println!("Find the product of all the two digit fractions with an unorthodox canceling method.\n");

    let mut total = [1, 1];
    for den in 10..100 {
        for num in 10..den {
            if unorthodox([num, den]) {
                total[0] *= num;
                total[1] *= den;
                total = reduce(total);
            }
        }
    }

    println!("{}/{}", total[0], total[1]);
}
