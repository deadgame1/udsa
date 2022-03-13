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
time : O(n^m * m) // tree heigh maximum of m, and branching factor is n, so n^m maximum nodes in a tree, + slice operation in
each iteration of a string of max length m, so multiply by m.
space : O(m^2) //at any given point max number of stack frames in stack can be m, i.e height of the tree. also in each recursive call we 
are maintain a suffix variable of length m. so m^m

Memoized
time: O(n*m^2)  //second m is coming from slice fn which is still there
space: O(m^2)
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
