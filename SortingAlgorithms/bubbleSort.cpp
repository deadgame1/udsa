#include <iostream>

using namespace std;

int* bubbleSort(int A[],int n){
    int flag;
    for(int i=0; i<n-1; i++){
        flag=0;
        for(int j=0; j<n-1-i; j++){
            if(A[j] > A[j+1]){
                swap(A[j],A[j+1]); //since array is always passed by address, no need to user & operator here, its already a pointer var
                flag=1;
            }
        }
        if(flag == 0){
            return A;
        }
    }

    return A;
}

void swap(int* A, int* B){
    int temp = *A;
    *A = *B;
    *B = temp;
}

int main(){
    int myArray[] = {8,5,7,3,2};

    int* sortedArray = bubbleSort(myArray, sizeof(myArray)/sizeof(myArray[0]));

    return 0;
}