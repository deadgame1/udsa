#include <iostream>

using namespace std;


void findMinMax(){
    int A[] = {5,8,3,9,6,2,10,7,-1,4};
    int sizeOfList = sizeof(A)/sizeof(A[0]);
    int i;
    int min = A[0];
    int max = A[0];
    for(i=1;i<sizeOfList;i++)
    {
        if(A[i] < min){
            min = A[i];
        }else if(A[i] > max){
            max = A[i];
        }
    }
    cout<<"min ="<<min<<endl;
    cout<<"max ="<<max<<endl;
}
int main(){
    findMinMax();
    
    return 0;
}