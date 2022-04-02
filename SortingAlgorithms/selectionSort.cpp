#include <iostream>

using namespace std;

int swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief This is Selection sort.
 * 
 * Time Analysis - 
 * Always takes - O(n^2) time
 * since comparisons - O(n^2)
 * 
 * Its good since swapping of data is less, swapping is O(n)
 * and each kth pass gives the first k smallest elements.
 * 
 * not adaptive and not stable
 * 
 * @return int 
 */
int main(){
    int A[10] = {9,8,7,6,5,4,3,2,1,0};
    int j,k;
    int arraySize = sizeof(A)/sizeof(A[0]);
    for(int i=0;i<arraySize-1;i++){
        j=i+1;
        k=i;
        while(j<arraySize){
            if(A[j]<A[k]) k=j;
            j++;
        }
        swap(&A[i],&A[k]);
    }

    for(int i=0;i<10;i++){
        cout<<A[i]<<" ";
    }

    return 0;
}