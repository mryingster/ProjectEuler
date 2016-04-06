// -*- compile-command: "rustc -o problem_019_rs problem_019.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 19:");
    println!("Find the total number of Sundays that fell on the first of the month in the 20th Century.\n");

    let mut total = 0;
    let mut day = 1;
    let mut month = 1;
    let mut year = 1901;
    let mut weekday = 2;
    let mut month_length = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

    while year < 2001 {
        // First of month is a Sunday!
        if day == 1 && weekday == 0 {
            total += 1;
        }

        weekday += 1;
        day += 1;

        // Increment Month
        if day > month_length[month] {
            day = 1;
            month += 1;
        }

        // Increment Year
        if month > 12 {
            month = 1;
            year += 1;

            // Leap Year
            if year % 4 == 0 {
                month_length[2] = 29;
            } else {
                month_length[2] = 28;
            }
        }

        // Keep track of week day
        if weekday > 6 {
            weekday = 0;
        }
    }

    println!("{}", total);
}
