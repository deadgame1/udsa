#include <iostream>

using namespace std;

void swap(int*A, int*B){
    int temp;
    temp = *A;
    *A = *B;
    *B = temp;
}
int partition(int *A, int l, int h){
    int pivot = A[l];
    int i=l,j=h;

    do{
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i<j)
            swap(&A[i],&A[j]);
    }while(i<j);

    swap(&A[l],&A[j]);
    return j;
}

void quickSort(int A[],int l, int h){
    int j;
    if(l<h){
        j=partition(A,l,h);
        quickSort(A,l,j);
        quickSort(A,j+1,h);
    }
}
int main(){
    //int A[] = {3,7,9,2,4,6,10,1,5,8,INT_LEAST16_MAX};
    int A[] = {3,47,48,49,INT_LEAST16_MAX};

    quickSort(A,0,4);

    for(int i=0;i<10;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

    return 0;
}