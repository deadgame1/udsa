/**
Write a function `canConstruct(target, wordBank)` that accepts a
target string and an array of strings.
The function should return a boolean indicating whether or not the
target` can be constructed by concatenating elements of the
wordBank array.
You may reuse elements of `wordBank as many times as needed.
 */

function canConstruct(target, wordBank, memo={}){
    if(target in memo) return memo[target];
    if(!target) return true;
    
    for(let word of wordBank){
        if(target.indexOf(word) === 0){
            let suffix = target.slice(word.length);
            if(canConstruct(suffix,wordBank,memo) == true){
                memo[target] = true;
                return true;
            } 
        }
    }

    memo[target] = false;
    return false;
}
/**
m=target.length, n= wordBank.length
Brute Force
time : O(n^m) // tree heigh maximum of m, and branching factor is n, so n^m maximum nodes in a tree
space : O(m) //at any given point max number of stack frames in stack can be m

Memoized
time: O(mn)
space: O(m)
*/

console.log(canConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"])); // true
console.log(canConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"])); // false
console.log(canConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"])); // true
console.log(canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
  "ee",
  "eee",
  "eeee",
  "eeeee",
  "eeeeee",
])); //false