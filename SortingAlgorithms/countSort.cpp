#include <iostream>

using namespace std;

int findMax(int list[], int sizeOfList){
    int max = list[0];
    for(int i=1;i<sizeOfList;i++){
        if(max<list[i])
            max = list[i];
    }

    return max;
}

void countSort(int list[], int sizeOfList){
    int maxNumberInList = findMax(list,sizeOfList);
    int *auxArray = new int[maxNumberInList+1];

    for(int i=0;i<maxNumberInList+1;i++)
        auxArray[i]=0;

    for(int i=0;i<sizeOfList;i++){
        auxArray[list[i]]++;
    }

    int j=0;
    while(j<maxNumberInList+1){
        if(auxArray[j] == 0){
            j++;
        }else{
            cout<<j<<" ";
            auxArray[j]--;
        }
    }
}

int main(){
    int A[] = {5,7,6,1,3,9,4,8,2};
    int n = sizeof(A)/sizeof(A[0]);
    countSort(A,n);

    return 0;
}