#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * @brief writing a fibonacci function with memoization
 * fib series - 1,1,2,3,5,8,13,21,34
 * @return int 
 */
static map<int, int> memo;
int fib(int n){
    try{
        return memo.at(n);
    }catch(...){
        //do nothing
    }
    if(n<=2){
        memo.insert(n,1);
        return 1;
    }
    int x = fib(n-2)+fib(n-1);
    memo.insert(n,x);
    return x;
}

int main(){

    //test cases
    cout<<fib(1)<<endl;
    // cout<<fib(2)<<endl;
    // cout<<fib(3)<<endl;
    // cout<<fib(4)<<endl;
    // cout<<fib(5)<<endl;
    // cout<<fib(6)<<endl;
    // cout<<fib(50)<<endl;

    // map<int, int> memo;
    // memo[1]=1;
    
    

    return 0;
}