#!/usr/bin/node

console.log("Project Euler - Problem 31:");
console.log("How many different ways can 2 pounds be made using any number of coins?\n");

var ways = 0;

// This is the naive approach, but it's fun
for (var twohundred=0; twohundred<=200; twohundred+=200){
    for (var onehundred=0; onehundred<=200; onehundred+=100){
        if (twohundred + onehundred > 200) break;
        for (var fifty=0; fifty<=200; fifty+=50){
            if (twohundred + onehundred + fifty > 200) break;
            for (var twenty=0; twenty<=200; twenty+=20){
                if (twohundred + onehundred + fifty + twenty > 200) break;
                for (var ten=0; ten<=200; ten+=10){
                    if (twohundred + onehundred + fifty + twenty + ten > 200) break;
                    for (var five=0; five<=200; five+=5){
                        if (twohundred + onehundred + fifty + twenty + ten + five > 200) break;
                        for (var two=0; two<=200; two+=2){
                            if (twohundred + onehundred + fifty + twenty + ten + five + two > 200) break;
                            ways += 1; // ones can fill in the remainder if the sum is <= 200
                        }
                    }
                }
            }
        }
    }
}

console.log(ways);
