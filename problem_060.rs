// -*- compile-command: "rustc -o problem_060_rs problem_060.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn is_prime(n: u32) -> bool {
    if n < 2 { return false; }
    if n == 2 { return true; }
    if n % 2 == 0 { return false; }

    let limit = (n as f64).sqrt() as u32;
    let mut i = 3;
    while i <= limit {
        if n % i == 0 { return false; }
        i += 2;
    }
    return true;
}

fn concat(a: usize, b:usize) -> u32 {
    return a as u32 * ((10 as f32).powf((b as f32).log10().floor() + 1.0) as u32) + b as u32;
}

fn check(a: usize, b:usize) -> bool {
    if is_prime(concat(a, b)) {
        if is_prime(concat(b, a)) {
            return true;
        }
    }
    return false;
}

fn lowest_sum(primes: Vec<usize>) -> u64 {
    for aa in 0..primes.len() {
        let a = primes[aa];

        for bb in aa..primes.len() {
            let b = primes[bb];
            if check(a, b) == false { continue; }

            for cc in bb..primes.len() {
                let c = primes[cc];
                if check(a, c) == false { continue; }
                if check(b, c) == false { continue; }

                for dd in cc..primes.len() {
                    let d = primes[dd];
                    if check(a, d) == false { continue; }
                    if check(b, d) == false { continue; }
                    if check(c, d) == false { continue; }

                    for ee in dd..primes.len() {
                        let e = primes[ee];
                        if check(a, e) == false { continue; }
                        if check(b, e) == false { continue; }
                        if check(c, e) == false { continue; }
                        if check(d, e) == false { continue; }
                        //println!("{}+{}+{}+{}+{}={}", a, b, c, d, e, a + b + c + d + e);
                        return (a + b + c + d + e) as u64;
                    }
                }
            }
        }
    }
    return 0;
}

fn main() {
    println!("Project Euler - Problem 60:");
    println!("Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.\n");

    // Find all primes below limit
    let mut prime_seive: [bool; 10000] = [true; 10000];
    let mut primes = Vec::new();
    for i in 2..prime_seive.len() {
        if prime_seive[i] == true {
            primes.push(i);
            let mut m = 2;
            let mut n = m*i;
            while n < prime_seive.len() {
                prime_seive[n] = false;
                m += 1;
                n = m*i;
            }
        }
    }

    println!("{}", lowest_sum(primes));
}
