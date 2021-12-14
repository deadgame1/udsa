#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;  

struct Array{
    //int *A;
    int A[10];
    int size;
    int length;
};
void display(struct Array arr){
    int i;
    cout<<"Elements of the array are"<<endl;
    for(i=0; i<arr.length; i++)
        cout<<arr.A[i]<<" ";
}
void append(struct Array *arr, int x){
    if(arr->length == arr->size){
        return; //array full
    }
    arr->A[arr->length] = x;
    arr->length++;
}
void insert(struct Array *arr, int x, int index){
    if(arr->length == arr->size){
        return; //array full
    }
    if(index >= 0 && index <= arr->length){
        for(int i=arr->length; i>index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}
int del(struct Array *arr, int index){
    if(arr->length == 0){
        return 0; //array is empty
    }
    int x;
    if(index >=0 && index < arr->length){
        x = arr->A[index];
        for(int i=index; i<arr->length-1; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->A[arr->length-1] = 0;
        arr->length--;
    }
    return x;
}
int get(struct Array arr, int index){
    if(index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}
void set(struct Array *arr, int index, int element){
    if(index >= 0 && index < arr->length)
        arr->A[index] = element;
}
int min(struct Array arr){
    int min = arr.A[0];
    for(int i=1;i<arr.length;i++)
        if(arr.A[i] < min)
            min = arr.A[i];
    return min;
}
int max(struct Array arr){
    int max = arr.A[0];
    for(int i=1;i<arr.length;i++)
        if(arr.A[i] > max)
            max = arr.A[i];
    return max;
}
int sum(struct Array arr){
    int sum = 0;
    for(int i=0;i<arr.length;i++)
        sum += arr.A[i];
    return sum;
}
float avg(struct Array arr){
    return sum(arr)/arr.length;
}
void reverseWithAux(struct Array *arr){
    int *B = new int[arr->length]; //creating in heap , since the size of an array depends on function parameter. so it has to be dynamic and not static
    for(int i=arr->length-1,j=0;i>=0;i--,j++){
        B[j] = arr->A[i];
    }
    for(int i=0;i<arr->length;i++){
        arr->A[i] = B[i];
    }
}
void swap(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(struct Array *arr){
    int temp;
    for(int i=0,j=arr->length-1;i<j;i++,j--){
        // temp = arr->A[i];
        // arr->A[i] = arr->A[j];
        // arr->A[j] = temp;
        swap(&arr->A[i],&arr->A[j]);
    }
}
void leftShift(struct Array *arr){
    for(int i=1; i<arr->length;i++){
        set(arr, i-1, arr->A[i]);
    }
    set(arr, arr->length-1, 0);
}
void rightShift(struct Array *arr){
    for(int i=arr->length-2; i>=0;i--){
        set(arr, i+1, arr->A[i]);
    }
    set(arr, 0, 0);
}
void leftRotate(struct Array *arr){
    int first = arr->A[0];
    for(int i=1; i<arr->length;i++){
        set(arr, i-1, arr->A[i]);
    }
    set(arr, arr->length-1, first);
}
void rightRotate(struct Array *arr){
    int last = arr->A[arr->length-1];
    for(int i=arr->length-2; i>=0;i--){
        set(arr, i+1, arr->A[i]);
    }
    set(arr, 0, last);
}
int isSorted(struct Array arr){
    for(int i=0;i<arr.length-1;i++){
        if(arr.A[i] > arr.A[i+1]){
            return 0;
        }
    }
    return 1;
}

//merges 2 sorted array and returns the result
struct Array * merge(struct Array arr, struct Array arr2){
    struct Array *arr3 = new struct Array;
    int i,j,k;

    for(i=j=k=0;i<arr.length && j<arr2.length;k++){
        if(arr.A[i] < arr2.A[j]){
            arr3->A[k] = arr.A[i];
            i++;
        }else{
            arr3->A[k] = arr2.A[j];
            j++;
        }
    }
    for(;i<arr.length;i++){
        arr3->A[k] = arr.A[i];
        k++;
    }
    for(;j<arr2.length;j++){
        arr3->A[k] = arr2.A[j];
        k++;
    }

    arr3->length = arr2.length + arr.length;

    return arr3;
}

struct Array * setUnion(struct Array arr, struct Array arr2){
    struct Array *arr3 = new struct Array;
    int i,j,k;
    i=j=k=0;

    //for(i=j=k=0; i<arr.length && j<arr2.length; k++){
    while(i<arr.length && j<arr2.length){
        if(arr.A[i] == arr2.A[j]){
            arr3->A[k] = arr.A[i];
            j++;
            i++;
        }else if(arr.A[i] < arr2.A[j]){
            arr3->A[k] = arr.A[i];
            i++;
        }else{
            arr3->A[k] = arr2.A[j];
            j++;
        }
        k++;
    }

    for(;i<arr.length;i++){
        arr3->A[k] = arr.A[i];
        k++;
    }
    for(;j<arr2.length;j++){
        arr3->A[k] = arr2.A[j];
        k++;
    }

    arr3->length = arr2.length + arr.length;

    return arr3;
}

struct Array * setUnionForUnsortedList(struct Array arr, struct Array arr2){
    struct Array *arr3 = new struct Array;
    int i,j,k;
    k=0;

    for(i=0;i<arr.length;i++){
        int found = false;
        for(j=0;j<arr.length;j++){
            if(arr.A[i] == arr2.A[j]){
                found = true;      
            }
        }
        if(!found){
            arr3->A[k] = arr.A[i];
            k++;
            arr3->length++;
        }
    }

    for(j=0;j<arr2.length;j++){
        arr3->A[k] = arr2.A[j];
        k++;
        arr3->length++;
    }

    return arr3;
}

struct Array * setIntersection(struct Array arr, struct Array arr2){
    struct Array *arr3 = new struct Array;
    int i,j,k;
    i=j=k=0;

    while(i<arr.length && j<arr2.length){
        if(arr.A[i] == arr2.A[j]){
            arr3->A[k] = arr.A[i];
            j++;
            i++;
            k++;
        }else if(arr.A[i] < arr2.A[j]){
            i++;
        }else{
            j++;
        }
        
    }

    arr3->length = k;

    return arr3;
}

struct Array * setIntersectionForUnsortedList(struct Array arr, struct Array arr2){
    struct Array *arr3 = new struct Array;
    int i,j,k;
    k=0;

    for(i=0;i<arr.length;i++){
        for(j=0;j<arr2.length;j++){
            if(arr.A[i] == arr2.A[j]){
                arr3->A[k++] = arr.A[i];
                arr3->length++;
            }
        }
    }

    return arr3;
}

//A-B
struct Array * setDifference(struct Array arr, struct Array arr2){
    struct Array *arr3 = new struct Array;
    int i,j,k;
    i=j=k=0;

    while(i<arr.length && j<arr2.length){
        if(arr.A[i] == arr2.A[j]){
            i++;
            j++;
        }else if(arr.A[i] < arr2.A[j]){
            arr3->A[k++] = arr.A[i++];
            arr3->length++;
        }else{
            //arr3->A[k++] = arr.A[j];
            //arr3->length++;
            j++;
        }
    }
    for(;i<arr.length;i++){
        arr3->A[k++] = arr.A[i];
        arr3->length++;
    }

    return arr3;
}

//A-B
struct Array * setDifferenceForUnsortedList(struct Array arr, struct Array arr2){
    struct Array *arr3 = new struct Array;
    int i,j,k;
    k=0;

    for(i=0;i<arr.length;i++){
        int found = false;
        for(j=0;j<arr2.length;j++){
            if(arr.A[i] == arr2.A[j]){
                found = true;
            }
        }
        if(!found){
            arr3->A[k++] = arr.A[i];
            arr3->length++;
        }
    }

    return arr3;
}

int main(){
    struct Array arr = {{2,4,6,8,10},10,5};
    struct Array arr2 = {{2,5,6,9,11},10,5};

    struct Array arr4 = {{8,4,7,3,5},10,5};
    struct Array arr5 = {{3,11,6,5,2},10,5};
    struct Array *arr3;

    arr3 = setDifference(arr,arr2);

    display(*arr3);

    return 0;
    // cout<<"Enter size of the array";
    // cin>>arr.size;

    // cout<<"Enter no. of elements";
    // cin>>arr.length;
    
    // arr.A = new int[arr.size];

    // cout<<"Enter the elements";
    // for(i=0;i<arr.length;i++)
    //     cin>>arr.A[i];

    // cout<<"Enter the element to delete";
    // cin>>ad;

    
}