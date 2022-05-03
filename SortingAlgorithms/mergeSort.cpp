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
    k=low;
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

    for(int i=low ;i<=high;i++){
        A[i] = B[i];
        //cout<<A[x]<<" ";
    }
    //cout<<endl;
}

void iterativeMerge(int A[],int sizeOfList){
    int p,low, mid, high;
    for(p=2;p<=sizeOfList;p=p*2){
        for(int i=0;i+p-1<sizeOfList;i=i+p){
            low = i;
            high = i+p-1;
            mid = (low+high)/2;
            merge(A,low,mid,high);
        }
    }
    if(p/2 < sizeOfList)
        merge(A,0,p/2-1,sizeOfList-1);
}

void recursiveMergeSort(int A[], int low, int high){
    if(low < high){
        int mid = low+high/2;
        recursiveMergeSort(A,low,mid);
        recursiveMergeSort(A,mid+1,high);
        merge(A, low, mid, high);
    }

}

int main(){
    int A[9] = {1,3,5,7,9,2,4,6,8};
    int n = sizeof(A)/sizeof(A[0]);
    iterativeMerge(A,n);

    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

    return 0;
}