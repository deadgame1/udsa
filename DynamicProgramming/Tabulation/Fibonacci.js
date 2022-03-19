/**
* Write a function fib(n)` that takes in a number as an argument.
The function should return the n-th number of the Fibonacci sequence.
The Oth number of the sequence is 0.
The 1st number of the sequence is 1.
To generate the next number of the sequence, we sum the previous two.
             n:      0, 1, 2, 3, 4, 5, 6, 7,  8,  9,
             fib(n): 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 
*/

function fib(n){
    const array = Array(n+1);
    array.fill(0);
    array[1]=1;
    //array.map((k)=>console.log(k));
    for(let i=0;i<n;i++){
        array[i+1] += array[i];
        array[i+2] += array[i]; 
    }

    return array[n];
}
console.log(fib(50));

/**
 * Time complexity - O(n)  //just looping throuh once a size of array n
 * Space - O(n) // array of size n required
 */