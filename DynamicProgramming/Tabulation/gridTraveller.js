/**
 * Say that you are a traveler on a 2D grid. You begin in the
top-left corner and your goal is to travel to the bottom-right
corner. You may only move down or right.
In how many ways can you travel to the goal on a grid with
dimensions m * n?
Write a function gridTraveler(m, n)` that calculates this.
 */

function gridTraveler(m,n){
    if(m==0 || n==0) return 1;
    const table = Array(m+1)
    .fill()
    .map((row) => row = Array(n+1).fill(0));
    //table.map((row) => row.fill(0));

    table[1][1]=1;

    for(let i=0; i<=m; i++){
        for(let j=0; j<=n; j++){
            if(j+1 <= n) table[i][j+1] += table[i][j];
            if(i+1 <= m) table[i+1][j] += table[i][j];
        }
    }

    return table[m][n];
}
/**
 * Time complexity - O(mn)  //traversing through a 2d array of size mn, i.e m rows, n columns
 * Space complexity - O(mn) //size of table
 */
 console.log(gridTraveler(1, 1)); // 1
 console.log(gridTraveler(2, 3)); // 3
 console.log(gridTraveler(3, 2)); // 3
 console.log(gridTraveler(3, 3)); // 6
 console.log(gridTraveler(18, 18)); // 2333606220