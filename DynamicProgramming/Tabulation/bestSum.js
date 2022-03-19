/**
 * Write a function bestSum(targetSum, numbers)` that takes in a
    targetSum and an array of numbers as arguments.
    The function should return an array containing the shortest
    combination of numbers that add up to exactly the targetSum.
    If there is a tie for the shortest combination, you may return any
    one of the shortest.
 */
function bestSum(targetSum, numbers){
    const table = Array(targetSum+1).fill(false);

    table[0] = [];

    for(let i=0;i<=targetSum+1;i++){
        if(table[i] !== false){
            for(let num of numbers){
                if(num+i <= targetSum){
                    if(table[num+i] === false) table[num+i] = [...table[i],num];
                    else {
                        let x = [...table[i],num];
                        if(x.length < table[num+i].length) table[num+i] = x;
                    };
                }
            }
        }
    }

    return table[targetSum];
}

/**
 * m=targetSum, n=numbers.length
 * //same as bestSum
 * Time - O(m*n*m) 
 * Space - O(m*m)  
 */

console.log(bestSum(8, [2, 3, 5])); // [3,5]
console.log(bestSum(7, [5, 3, 4, 7])); // [7]
console.log(bestSum(8, [2, 3, 5])); // [3, 5]
console.log(bestSum(8, [1, 4, 5])); // [4, 4]
console.log(bestSum(100, [1, 2, 5, 25])); // [25, 25, 25, 25]