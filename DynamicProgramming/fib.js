function fib(n, memo={}){
    if(n in memo){
        return memo[n];
    }
    if(n<=2){
        memo[n]=1;
        return 1;
    }

    let x = fib(n-2,memo)+fib(n-1,memo);
    memo[n] = x;
    return x;
}


console.log(fib(1));
console.log(fib(2));
console.log(fib(3));
console.log(fib(4));
console.log(fib(5));
console.log(fib(6));
console.log(fib(7));
console.log(fib(50));