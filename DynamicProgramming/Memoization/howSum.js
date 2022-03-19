/**
    Write a function howSum(targetSum, numbers)` that takes in a
    targetSum and an array of numbers as arguments.
    The function should return an array containing any combination of
    elements that add up to exactly the targetSum. If there is no
    combination that adds up to the targetSum, then return null.
    If there are multiple combinations possible, you may return any
    single one.
 */
function howSum(targetSum, array, memo={}){
    if(targetSum in memo) return memo[targetSum];
    if(targetSum == 0) return [];
    if(targetSum < 0) return null;

    for(let i=0;i<array.length;i++){
        let diff = targetSum - array[i];
        let result = howSum(diff,array,memo);
        if(result !== null){
            let x = [...result,array[i]]; 
            memo[targetSum] = x;
            return x;
        }
    }

    memo[targetSum] = null;
    return null;
}
// m = targetSum , n = array.length
// Brute Force
// time: 0(n^m * m) exponential
// space: 0(m)
//
// Memoized
// time: 0(n*m^2) polynomial
// space: O(m^2)   //memo object will have atmost m keys, and each corresponding value will at those keys will be an array of size m, so m times m

console.log(howSum(7, [2, 3])); //3,2,2
console.log(howSum(8, [2,3,5])); //2,2,2,2
console.log(howSum(7, [5,3,4,7])); //[4,3]
console.log(howSum(7, [2,4])); //null
console.log(howSum(300, [7,14])); //null

