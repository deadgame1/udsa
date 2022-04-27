#include <iostream>

using namespace std;

/**
 * @brief merge 2 sorted list into 1 sorted list
 * please note that the 2 sorted list is present in one array.
 * needs aux array
 * 
 * @param A 
 * @param low 
 * @param mid 
 * @param high 
 */
void merge(int A[],int low, int mid, int high){
    int i,j,k;
    i=low;
    j=mid+1;
    k=0;
    int B[100];

    while(i<=mid && j<=high){
        if(A[i] <= A[j]){
            B[k++] = A[i++];
        }else{
            B[k++] = A[j++];
        }
    }

    for(;i<=mid;i++)
        B[k++]=A[i];

    for(;j<=high;j++)
        B[k++]=A[j];

    for(int x=low, y=0;x<=high,y<=high-low;x++,y++){
        A[x] = B[y];
        cout<<A[x]<<" ";
    }
    cout<<endl;
}

int main(){
    int A[8] = {3,5,7,9,2,4,6,8};

    merge(A,0,3,7);

    return 0;
}