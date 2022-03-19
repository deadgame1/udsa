/**
 * Write a function `allConstruct(target, wordBank)` that accepts a
    target string and an array of strings.
    The function should return a 2D array containing all of the ways
    that the 'target` can be constructed by concatenating elements of
    the wordBank` array. Each element of the 2D array should represent
    one combination that constructs the target`.
    You may reuse elements of `wordBank` as many times as needed.
 */

function allConstruct(target, wordBank){
    const table = Array(target.length + 1)
    .fill()
    .map((row) => row = new Array());
    table[0] = [[]];

    for(let i=0;i<table.length;i++){
        if(table[i].length !== 0){
            for(let word of wordBank){
                if(target.slice(i,i+word.length) === word){
                    for(let way of table[i]){
                        table[i+word.length].push([...way,word]);
                    }
                }
            }
        }
    }

    return table[target.length];
}

/**
 * Analysis
 * m=target.length, n=wordBank.length
 * Time complexity
 * Time - O(n^m)
 * Space - O(n^m)
 */
console.log(allConstruct('purple', ['purp', 'p', 'ur', 'le', 'purpl'])); // 2
console.log(allConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd" ])); // 1
console.log(allConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"])); // 0
console.log(allConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"])); // 4
console.log(allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
   "ee",
   "eee",
   "ееее",
   "eееее",
   "eеееее",
])); // 0