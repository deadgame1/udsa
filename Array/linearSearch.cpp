#include <iostream>

using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};
int LinearSearch(struct Array arr, int element){
    for(int i=0;i<arr.length;i++)
        if(arr.A[i] == element)
            return i;
    return -1;//not found
}
int main(){
    struct Array arr = {{2,4,6,8}, 10, 4};

    cout<<LinearSearch(arr, 8);
}