// -*- compile-command: "rustc -o problem_061_rs problem_061.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn is_match(a: usize, b: usize) -> bool {
    if a % 100 == b / 100 {
        return true;
    }
    return false;
}

fn contains(array: [usize; 6], i: usize) -> bool {
    for j in 0..array.len() {
        if array[j] == i {
            return true;
        }
    }
    return false;
}

fn main() {
    println!("Project Euler - Problem 61:");
    println!("Find the sum of the only ordered set of six cyclic 4-digit numbers for which each polygonal type: triangle, square, pentagonal, hexagonal, heptagonal, and octagonal, is represented by a different number in the set.\n");

    let mut gonal = Vec::new();

    // Generate our 4 digit numbers
    for n in 1..10000 {
        let tri = n*(n+1)/2;
        if tri > 999 && tri < 10000 { gonal.push([3, tri]); }
        let sqr = n*n;
        if sqr > 999 && sqr < 10000 { gonal.push([4, sqr]); }
        let pen = n*(3*n-1)/2;
        if pen > 999 && pen < 10000 { gonal.push([5, pen]); }
        let hex = n*(2*n-1);
        if hex > 999 && hex < 10000 { gonal.push([6, hex]); }
        let hep = n*(5*n-3)/2;
        if hep > 999 && hep < 10000 { gonal.push([7, hep]); }
        let oct = n*(3*n-2);
        if oct > 999 && oct < 10000 { gonal.push([8, oct]); }
    }

    // Brute force it!
    for a in 0..gonal.len() {
        let mut history = [gonal[a][0], 0, 0, 0, 0, 0];

        for b in 0..gonal.len() {
            if is_match(gonal[a][1], gonal[b][1]) == false || contains(history, gonal[b][0]) == true { continue; }
            history[1] = gonal[b][0];

            for c in 0..gonal.len() {
                if is_match(gonal[b][1], gonal[c][1]) == false || contains(history, gonal[c][0]) == true { continue; }
                history[2] = gonal[c][0];

                for d in 0..gonal.len() {
                    if is_match(gonal[c][1], gonal[d][1]) == false || contains(history, gonal[d][0]) == true { continue; }
                    history[3] = gonal[d][0];

                    for e in 0..gonal.len() {
                        if is_match(gonal[d][1], gonal[e][1]) == false || contains(history, gonal[e][0]) == true { continue; }
                        history[4] = gonal[e][0];

                        for f in 0..gonal.len() {
                            if is_match(gonal[e][1], gonal[f][1]) == false || contains(history, gonal[f][0]) == true { continue; }
                            history[5] = gonal[f][0];

                            if is_match(gonal[f][1], gonal[a][1]) {
                                let sum = gonal[a][1] + gonal[b][1] + gonal[c][1] + gonal[d][1] + gonal[e][1] + gonal[f][1];
                                println!("{}", sum);

                                /*
                                // Debug
                                println!("{}({}) -> {}({}) -> {}({}) -> {}({}) -> {}({}) -> {}({})",
                                         gonal[a][1], gonal[a][0],
                                         gonal[b][1], gonal[b][0],
                                         gonal[c][1], gonal[c][0],
                                         gonal[d][1], gonal[d][0],
                                         gonal[e][1], gonal[e][0],
                                         gonal[f][1], gonal[f][0]);
                                 */
                            }
                        }
                    }
                }
            }
        }
    }
}
