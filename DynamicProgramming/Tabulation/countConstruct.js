/**
 * Write a function `countConstruct(target, wordBank)` that accepts a
    target string and an array of strings.
    The function should return the number of ways that the `target` can
    be constructed by concatenating elements of the `wordBank` array.
    You may reuse elements of `wordBank` as many times as needed.
 */
function countConstruct(target, wordBank){
    const table = Array(target.length + 1).fill(0);

    table[0] = 1;

    for(let i=0;i<=table.length;i++){
        if(table[i] > 0){
            for(let word of wordBank){
                if(target.slice(i,i+word.length) === word){
                    table[i+word.length] += table[i]; 
                }
            }
        }
    }

    return table[target.length];
}

/**
 * m=target.length, n=wordBank.length
 * Complexity analysis - 
 * Time - O(m*n*m)
 * Space - O(m)
 */

console.log(countConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd","ef"])); // true
console.log(countConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"])); // false
console.log(countConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"])); // true
console.log(countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee", [
  "e",
  "ee",
  "eee",
  "eeee",
  "eeeee",
  "eeeeee",
])); // false