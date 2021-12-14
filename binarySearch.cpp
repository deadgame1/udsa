#include <stdio.h>
#include <iostream>

using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

//iterative binary search
int BinarySearch(struct Array arr, int elem){
    int low = 0;
    int high = arr.length - 1;
    int mid;
    while (low <= high){
        mid = (low + high) / 2;
        if(elem == arr.A[mid])
            return mid;
        else if(elem < arr.A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    return -1; //unsuccessfull search
}
int main()
{
    struct Array arr = {{2,4,6,8,10},10,5};

    cout<<BinarySearch(arr, 4);

    // for(int i=0;i<arr.length;i++)
    //     cout<<arr.A[i]<<endl;

    return 0;
}