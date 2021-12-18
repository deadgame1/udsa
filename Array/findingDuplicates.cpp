#include <iostream>

using namespace  std;

/**
 * @brief finding duplicates in a SORTED list
 * multiple repeats should not be printed again.
 * so eg - 15,15,15 - 15 should be printed only once.
 * 
 */
void findDuplicates(){
    int A[10]={3,6,8,8,10,12,15,15,15,20};
    int lastDup=0;
    for(int i=0;i<10;i++){
        if(A[i] == A[i+1] && lastDup != A[i]){
            lastDup = A[i];
            cout<<A[i]<<endl;
        }
    }
}

/**
 * @brief same as findDuplicates, but finds the count of duplicates also, how many times the number repeated
 * also for SORTED array.
 */
void findDuplicatesAndCountDuplicates(){
    int A[10]={3,6,8,8,10,12,15,15,15,20};
    for(int i=0;i<9;i++){ //i goes till n-1 unlike above function where it goes till n
        if(A[i] == A[i+1]){
            int j = i+1;
            while(A[i] == A[j]) j++;
            cout<<"Duplicate elem - "<<A[i]<<", count - "<<j-i<<endl;
            i = j-1;
        }
    }
}
int main(){
    findDuplicatesAndCountDuplicates();

    return 0;
}