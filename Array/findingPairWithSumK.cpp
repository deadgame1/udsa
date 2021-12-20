#include <iostream>

using namespace std;

/**
 * @brief finding a pair with sum = k,
 * list is unsorted, with no duplocates
 * @param k 
 */
void findPairWithSumK(int k){
    int A[10] = {4,7,9,8,10,2,3,1,6,0}; //unsorted list with no duplicates
    int i,j;
    for(i=0;i<9;i++){
        for(j=i+1;j<10;j++){
            if(A[i] + A[j] == k){
                cout<<A[i]<<" + "<<A[j]<<" = "<<k<<endl;
            }
        }
    }
}

/**
 * @brief finding a pair with sum = k,
 * list is unsorted, with no duplicates
 * @param k 
 */
void findPairWithSumkUsingHashing(int k){
    int n = 10; //list size
    int A[n] = {4,7,9,8,10,2,3,1,6,0}; //unsorted list with no duplicates
    int maxElemInList = 10; //hardcoded, but can find using max() function.
    int H[maxElemInList+1] = {0};
    int i,j;
    for(j=0;j<maxElemInList+1;j++){
        int complement = k - j;
        if(H[complement] > 0){
            cout<<j<<" + "<<complement<<" = "<<k<<endl;
        }
        if(j<n){
            H[A[j]]++;
        }
    }
}

void findPairWithSumForSortedList(int k) //k is sum
{
    int A[] = {1,3,4,5,6,8,9,10,12,14};
    int i=0;
    int j= (sizeof(A)/sizeof(A[0])) - 1;
    while(i < j){
        int sum = A[i] + A[j];
        if(sum == k){
            cout<<"pair - "<<A[i]<<"+"<<A[j]<<" = "<<k<<endl;
            i++; j--;
        }else if(sum > k){
            j--;
        }else{
            i++;
        }
    }
}

int main(){
    findPairWithSumForSortedList(10);

    return 0;
}