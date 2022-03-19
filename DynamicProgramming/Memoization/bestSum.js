/**
    Write a function bestSum(targetSum, numbers)` that takes in a
    targetSum and an array of numbers as arguments.
    The function should return an array containing the shortest
    combination of numbers that add up to exactly the targetSum.
    If there is a tie for the shortest combination, you may return any
    one of the shortest. 
*/
function bestSum(targetSum, array, memo = {}){
    if(targetSum in memo) return memo[targetSum];
    if(targetSum == 0) return [];
    if(targetSum < 0) return null;

    let best = null;
    for(let i=0;i<array.length;i++){
        let diff = targetSum - array[i];
        let res = bestSum(diff, array, memo);
        if(res !== null){
            let combination = [...res,array[i]];
            if(best === null || combination.length < best.length){
                best = combination;
            }
        }
    }

    memo[targetSum] = best;
    return best;
}

// m = targetSum , n = array.length
// Brute Force
// time: 0(n^m * m)  exponential
// space: 0(m^2) polynomial since m for stack frames, and also for storing `best` array at each recursive call, that array can be of size upto m
// so m*m
//
// Memoized
// time: 0(n*m^2)
// space: O(m^2)

console.log(bestSum(7, [5, 3, 4, 7])); // [7]
console.log(bestSum(8, [2, 3, 5])); // [3, 5]
console.log(bestSum(8, [1, 4, 5])); // [4, 4]
console.log(bestSum(100, [1, 2, 5, 25])); // [25, 25, 25, 25]