#include <iostream>

using namespace std;

int main(){
    int A[10] = {9,8,7,6,5,4,3,2,1,0};
    int x,j;
    for(int i=1;i<(sizeof(A)/sizeof(A[0]));i++){
        j=i-1;
        x=A[i];
        while(j>-1 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }

    for(int i=0;i<10;i++){
        cout<<A[i]<<" ";
    }

    return 0;
}