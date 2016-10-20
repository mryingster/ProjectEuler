// -*- compile-command: "rustc -o problem_243_rs problem_243.rs" -*-
// Copyright (c) 2016 Michael Caldwell

#[derive(Copy, Clone)]
struct Result {
    number: u64,
    phi: u64,
    ratio: f64,
}

fn totient(mut n: u64, primes: [usize; 10000], pcount: usize) -> Result {
    let mut result = Result {number: n, phi: n, ratio: 0.0};
    let mut i: usize = 0;

    while n > 1 && i < pcount {
        if n % primes[i] as u64 == 0 {
            while n % primes[i] as u64 == 0 {
                n /= primes[i] as u64;
            }
            result.phi = (result.phi as f64 * (1.0 - (1.0/(primes[i] as f64)))) as u64;
        }
        i += 1;
    }

    result.ratio = result.phi as f64 / ((result.number-1) as f64);
    return result;
}

fn main() {
    println!("Project Euler - Problem 243:");
    println!("Find the smallest denominator d, having a resilience R(d) < 15499/94744.\n");

    // Use sieve to get primes
    let mut primes = [0; 10000];
    let mut pindex = 0;
    let mut prime_sieve: [bool; 200000] = [true; 200000];
    for i in 2..prime_sieve.len() {
        if prime_sieve[i] == true {
            primes[pindex] = i;
            pindex += 1;
            let mut m = 2;
            let mut n = m*i;
            while n < prime_sieve.len() {
                prime_sieve[n] = false;
                m += 1;
                n = m*i;
            }
        }
        if pindex == 10000 { break; }
    }

    let limit = 15499.0 / 94744.0;
    let mut n = 1;

    // Multiply by primes until ratio is smaller than limit,
    // then back off by 1 so it is bigger
    for i in 0..primes.len() {
        n *= primes[i];
        let phi = totient(n as u64, primes, primes.len());
        if phi.ratio < limit {
            n /= primes[i];
            break;
        }
    }

    // Multiply new n value by 1, 2, 3, etc until it satisfies constraints
    for i in 1..10 {
        let t = n * i;
        let phi = totient(t as u64, primes, primes.len());
        if phi.ratio < limit {
            println!("{}", t);
            break;
        }
    }
}

