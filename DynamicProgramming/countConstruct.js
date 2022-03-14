/**
 Write a function `countConstruct(target, wordBank)` that accepts a
target string and an array of strings.
The function should return the number of ways that the target` can
be constructed by concatenating elements of the wordBank array.
You may reuse elements of wordBank as many times as needed.
 */

function countConstruct(target, wordBank, memo={}){
    if(target in memo) return memo[target];
    if(!target) return 1;

    let combinations = 0;
    for(let word of wordBank){
        if(target.indexOf(word) === 0){
            let suffix = target.slice(word.length);
            let result = countConstruct(suffix, wordBank, memo);
            combinations += result;
        }
    }

    memo[target] = combinations;
    return combinations;
}

/**
 * Brute force
 * Time: O(n^m*m)
 * Space: O(m^2)
 * 
 * Memoized
 * Time: O(m^2*n) 
 * Space: O(m^2)
 */

console.log(countConstruct("abcdef",["ab","abc","cd","def","abcd"])); //1
console.log(countConstruct("purple",["purp","p","ur","le","purpl"])); //2 
console.log(countConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"])); // 0
console.log(countConstruct("enterapotentpot", ["a", "p", "ent", "enter","ot","o","t"]));//4
console.log(countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",[
    "e",
    "ee",
    "еее",
    "ееее",
    "еееее",
    "ееееее",
])); //0