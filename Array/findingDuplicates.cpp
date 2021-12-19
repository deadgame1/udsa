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

/**
 * @brief finding duplicates and count in an unsorted list
 * 
 */
void findingDuplicatesAndCountInUnsortedList(){
    int n = 10; //no of elements suppose.
    int A[n]={8,1,15,8,5,3,15,1,15,1}; //unsorted list
    int i,j;
    for(i=0;i<n-1;i++){
        int count = 1;
        if(A[i] != -1){
            for(j=i+1;j<n;j++){
                if(A[i] == A[j]){
                    A[j] = -1;
                    count++;
                }
            }
            if(count > 1){
                cout<<A[i]<<" - repeating number, with count = "<<count<<endl;
            }
        }
    }
}

/**
 * @brief finding duplicates and count in an unsorted list using Hashing
 * 
 */
void findingDuplicatesAndCountInUnsortedListUsingHashing(){
    int n = 10; //no of elements suppose.
    int A[n]={8,1,15,8,5,3,15,1,15,1}; //unsorted list
    int maxElementInA = 15; //hardcoded here, but can be fetched from max() function of array
    int H[maxElementInA+1] = {0};

    int i,j;
    for(i=0;i<n;i++){
        H[A[i]]++;
    }
    for(j=0;j<maxElementInA+1;j++){
        if(H[j] > 1){
            cout<<j<<" - repeating number, with count = "<<H[j]<<endl;
        }
    }
}

int main(){
    findingDuplicatesAndCountInUnsortedListUsingHashing();

    return 0;
}