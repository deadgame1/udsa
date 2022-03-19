/**
 * Write a function howSum(targetSum, numbers)` that takes in a
targetSum and an array of numbers as arguments.
The function should return an array containing any combination of
elements that add up to exactly the targetSum.
If there is no combination that adds up to the targetSum, then
return null.
If there are multiple combinations possible, you may return any
single one.
 */
function howSum(targetSum, numbers){
    const table = Array(targetSum+1).fill(false);

    table[0] = [];

    for(let i=0;i<=targetSum+1;i++){
        if(table[i] !== false){
            for(let num of numbers){
                if(num+i <= targetSum){
                    table[num+i] = [...table[i],num];
                }
            }
        }
    }

    return table[targetSum];
}

/**
 * m=target length, n=number 
 * Time complexity - O(m*n*m)  //in tutorial O(m*n*m) extra m factor coming from copying array
 * Space - O(m^2)
 */
console.log(howSum(8, [2, 3, 5])); // 
console.log(howSum(7, [3, 4, 5])); // 
console.log(howSum(7, [2, 3])); // [3, 2, 2]
console.log(howSum(7, [5, 3, 4, 7])); // [4,3]
console.log(howSum(7, [2, 4])); // null
console.log(howSum(8, [2, 3, 5])); // [2, 2, 2, 2]
console.log(howSum(300, [7, 14])); // null