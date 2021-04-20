function nextPermutation(a) {
    const len = a.length;

    // Find the largest index k such that a[k] < a[k + 1]
    var k = 0;
    for (var i = 0; i<len-1; i++)
        if (a[i] < a[i+1])
            k = i;

    // Find the largest index l greater than k such that a[k] < a[l]
    var l = 0;
    for (var i=k; i<len; i++)
        if (a[k] < a[i])
            l = i;

    // Swap the value of a[k] with that of a[l]
    var t = a[k];
    a[k] = a[l];
    a[l] = t;

    // Reverse the sequence from a[k + 1] up to and including the final element a[n]
    if (k < 8)
    {
        var r = [];
	for (var i=0; i<len; i++)
	    r.push(0);

        var j = 9;
        for (var i=k+1; i<len; i++)
        {
            r[j] = a[i];
            j -= 1;
        }
        for (var i=(k+1); i<len; i++)
            a[i] = r[i];
    }
}

console.log("Project Euler - Problem 24:");
console.log("Find the 1,000,000th lexiconic permutation of the numbers 0, 1, 2, 3, 4, 5, 6, 7, 8, and 9.\n");

var array = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];

for (var i=0; i<1000000; i++)
    nextPermutation(array);

console.log(array.join(""));
