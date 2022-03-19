/**
Write a function allConstruct(target, wordBank)` that accepts a
target string and an array of strings.
The function should return a 2D array containing all of the ways
that the `target` can be constructed by concatenating elements of
the `wordBank` array. Each element of the 2D array should represent
one combination that constructs the `target`.
You may reuse elements of `wordBank` as many times as needed.
 */
function allConstruct(target, wordBank, memo={}){
    if(target in memo) return memo[target];
    if(!target) return [[]];

    let combinations = [];
    for(let word of wordBank){
        if(target.indexOf(word) === 0){
            let suffix = target.slice(word.length);
            let result = allConstruct(suffix, wordBank,memo);
            if(result.length > 0){
                let a = result.map(way => [word,...way]);
                combinations.push(...a);
            }
        }
    }

    memo[target] = combinations;
    return combinations;
}

console.log(allConstruct("purple",["purp","p","ur","le","purpl"]));
console.log(allConstruct("abcdef", [ "ab", "abc", "cd", "def", "abcd", "ef", "c"]));
console.log(allConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"])); //[]
console.log(allConstruct("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaz", ["a", "aa", "aaa", "aaaa", "aaaaa"])); //[]