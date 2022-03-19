/**
 *  Write a function `canConstruct(target, wordBank)` that accepts a
    target string and an array of strings.
    The function should return a boolean indicating whether or not the
    target` can be constructed by concatenating elements of the
    wordBank` array.
    You may reuse elements of `wordBank` as many times as needed.
 */
function canConstruct(target, wordBank){
    const table = Array(target.length + 1).fill(false);

    table[0] = true;

    for(let i=0;i<=target.length;i++){
        if(table[i] === true){    
            for(let word of wordBank){
                if(target.slice(i, i+word.length) === word){
                    table[i+word.length] = true;
                }
            }
        }
    }

    return table[target.length];
}

/**
 * Analysis - 
 * Time - O(m*n*m) // m outer loop, n inner loop, another m for slicing a string ,max slice could be target
 * Space - O(m) //
 */

console.log(canConstruct("abcdef",["ab","abc","abcd","ef","cd"])); //true
console.log(canConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"])); // true
console.log(canConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"])); // false
console.log(canConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"])); // true
console.log(canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
  "e",
  "ee",
  "eee",
  "eeee",
  "eeeee",
  "eeeeee",
])); // false