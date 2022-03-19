/**
Write a function allConstruct(target, wordBank)` that accepts a
target string and an array of strings.
The function should return a 2D array containing all of the ways
that the `target` can be constructed by concatenating elements of
the `wordBank` array. Each element of the 2D array should represent
one combination that constructs the `target`.
You may reuse elements of `wordBank` as many times as needed.
 */
function allConstruct(target, wordBank){
    if(!target) return [[]];

    let combinations = [];
    for(let word of wordBank){
        if(target.indexOf(word) === 0){
            let suffix = target.slice(word.length);
            let result = allConstruct(suffix, wordBank);
            if(result.length > 0){
                let a = result.map(way => [word,...way]);
                combinations.push(...a);
            }
        }
    }

    return combinations;
}

console.log(allConstruct("purple",["purp","p","ur","le","purpl"]));
console.log(allConstruct("abcdef", [ "ab", "abc", "cd", "def", "abcd", "ef", "c"]));
