// -*- compile-command: "rustc -o problem_070_rs problem_070.rs" -*-
// Copyright (c) 2016 Michael Caldwell

#[derive(Copy, Clone)]
struct Result {
    number: u64,
    phi: u64,
    ratio: f64,
}

fn get_signature(mut n: u64) -> u64 {
    let mut sig = 0;
    while n > 0 {
        sig += (10 as f64).powi((n % 10) as i32) as u64;
        n /= 10;
    }
    return sig;
}

fn get_length(n: u64) -> u64 {
    return ((n as f32).log10().floor() + 1.0) as u64;
}

fn compare(a: u64, b: u64) -> bool {
    if get_length(a) != get_length(b) {
        return false;
    }

    if get_signature(a) != get_signature(b) {
        return false;
    }
    return true;
}

fn totient(mut n: u64, primes: [usize; 5000], pcount: usize, min: f64) -> u64 {
    let mut result = n;
    let threshold = (n as f64) / min;
    let mut i: usize = 0;

    while n > 1 && i < pcount {
        if n % primes[i] as u64 == 0 {
            while n % primes[i] as u64 == 0 {
                n /= primes[i] as u64;
            }
            result = (result as f64 * (1.0 - (1.0/(primes[i] as f64)))) as u64;
            if result as f64 <= threshold {
                return 1;
            }
        }
        i += 1;
    }

    return result;
}

fn main() {
    println!("Project Euler - Problem 70:");
    println!("Find the value of n, 1 < n < 10^7, for which phi(n) is a permutation of n and the ratio n/phi(n) produces a minimum.\n");

    // Find first 5000 primes using seive
    let mut primes = [0; 5000];
    let mut pindex = 0;
    let mut prime_seive: [bool; 100000] = [true; 100000];
    for i in 2..prime_seive.len() {
        if prime_seive[i] == true {
            primes[pindex] = i;
            pindex += 1;
            let mut m = 2;
            let mut n = m*i;
            while n < prime_seive.len() {
                prime_seive[n] = false;
                m += 1;
                n = m*i;
            }
        }
        if pindex == 5000 { break; }
    }

    // Define limits
    let max = 10000000;
    let search_max = (max as f64).sqrt() as u64;
    let mut result = Result {number: 0, phi:0, ratio:2.0};

    // Solve problem
    let mut a = 100;
    while primes[a] < search_max as usize {
        let mut n = primes[a] as u64;
        let mut b = a;
        while n < max {
            // Create a number to try that is product of 2 primes
            n = (primes[a] * primes[b]) as u64;

            // Calculate phi using totient
            let phi = totient(n, primes, primes.len(), result.ratio);

            // Get the ratio of phi to n
            let ratio = (n as f64)/(phi as f64);

            // See if we have better ratio
            if ratio < result.ratio {

                // Verify that it is a permutation
                if compare(n, phi) == true {

                    // Record results
                    result.number = n;
                    result.phi = phi;
                    result.ratio = ratio;

                    //println!("phi({})={} ({})", n, phi, ratio);
                }
            }
            b += 1;
        }
        a += 1;
    }
    println!("{}", result.number);
}
