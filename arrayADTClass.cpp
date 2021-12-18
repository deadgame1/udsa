#include <iostream>

using namespace std;  

class Array{
private:
    int *A;
    int size;
    int length;
    void swap(int *a, int *b);
public:
    Array(){
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz){
        size = sz;
        A = new int[size];
        length = 0;
    }
    ~Array(){
        delete []A;
    }
    void display();
    void append(int x);
    void insert(int x,int index);
    int del(int index);
    int get(int index);
    void set(int index, int element);
    int min();
    int max();
    int sum();
    float avg();
    void reverseWithAux();
    void reverse();
    void leftShift();
    void rightShift();
    void leftRotate();
    void rightRotate();
    int isSorted();
    Array* merge(Array arr2);
    Array* setUnion(Array arr2);
    Array* setUnionForUnsortedList(struct Array arr2);
    Array* setIntersection(Array arr2);
    Array* setIntersectionForUnsortedList(Array arr2);
    Array* setDifference(Array arr2);
    Array* setDifferenceForUnsortedList(Array arr2);
};

void Array::display()
{
    int i;
    cout<<"Elements of the array are"<<endl;
    for(i=0; i<length; i++)
        cout<<A[i]<<" ";
}
void Array::append(int x)
{
    if(length == size){
        return; //array full
    }
    A[length] = x;
    length++;
}
void Array::insert(int x, int index)
{
    if(length == size){
        return; //array full
    }
    if(index >= 0 && index <= length){
        for(int i=length; i>index; i--){
            A[i] = A[i-1];
        }
        A[index] = x;
        length++;
    }
}
int Array::del(int index)
{
    if(length == 0){
        return 0; //array is empty
    }
    int x;
    if(index >=0 && index < length){
        x = A[index];
        for(int i=index; i<length-1; i++){
            A[i] = A[i+1];
        }
        A[length-1] = 0;
        length--;
    }
    return x;
}
int Array::get(int index)
{
    if(index >= 0 && index < length)
        return A[index];
    return -1;
}
void Array::set(int index, int element)
{
    if(index >= 0 && index < length)
        A[index] = element;
}
int Array::min()
{
    int min = A[0];
    for(int i=1;i<length;i++)
        if(A[i] < min)
            min = A[i];
    return min;
}
int Array::max()
{
    int max = A[0];
    for(int i=1;i<length;i++)
        if(A[i] > max)
            max = A[i];
    return max;
}
int Array::sum()
{
    int sum = 0;
    for(int i=0;i<length;i++)
        sum += A[i];
    return sum;
}
float Array::avg()
{
    return sum()/length;
}
void Array::reverseWithAux()
{
    int *B = new int[length]; //creating in heap , since the size of an array depends on function parameter. so it has to be dynamic and not static
    for(int i=length-1,j=0;i>=0;i--,j++){
        B[j] = A[i];
    }
    for(int i=0;i<length;i++){
        A[i] = B[i];
    }
}
void Array::swap(int *a, int *b) //check this function
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Array::reverse()
{
    int temp;
    for(int i=0,j=length-1;i<j;i++,j--){
        // temp = arr->A[i];
        // arr->A[i] = arr->A[j];
        // arr->A[j] = temp;
        swap(&A[i],&A[j]);
    }
}
void Array::leftShift()
{
    for(int i=1; i<length;i++){
        set(i-1, A[i]);
    }
    set(length-1, 0);
}
void Array::rightShift()
{
    for(int i=length-2; i>=0;i--){
        set(i+1, A[i]);
    }
    set(0, 0);
}
void Array::leftRotate()
{
    int first = A[0];
    for(int i=1; i<length;i++){
        set(i-1, A[i]);
    }
    set(length-1, first);
}
void Array::rightRotate()
{
    int last = A[length-1];
    for(int i=length-2; i>=0;i--){
        set(i+1, A[i]);
    }
    set(0, last);
}
int Array::isSorted()
{
    for(int i=0;i<length-1;i++){
        if(A[i] > A[i+1]){
            return 0;
        }
    }
    return 1;
}

//merges 2 sorted array and returns the result
Array* Array::merge(Array arr2)
{
    Array *arr3 = new Array(length + arr2.length); 
    int i,j,k;

    for(i=j=k=0;i<length && j<arr2.length;k++){
        if(A[i] < arr2.A[j]){
            arr3->A[k] = A[i];
            i++;
        }else{
            arr3->A[k] = arr2.A[j];
            j++;
        }
    }
    for(;i<length;i++){
        arr3->A[k] = A[i];
        k++;
    }
    for(;j<arr2.length;j++){
        arr3->A[k] = arr2.A[j];
        k++;
    }

    arr3->length = arr2.length + length;

    return arr3;
}
Array* Array::setUnion(Array arr2) //check this function
{
    Array *arr3 = new Array(size + arr2.size);
    int i,j,k;
    i=j=k=0;

    while(i<length && j<arr2.length){
        if(A[i] == arr2.A[j]){
            arr3->A[k] = A[i];
            j++;
            i++;
        }else if(A[i] < arr2.A[j]){
            arr3->A[k] = A[i];
            i++;
        }else{
            arr3->A[k] = arr2.A[j];
            j++;
        }
        k++;
        arr3->length++;
    }

    for(;i<length;i++){
        arr3->A[k] = A[i];
        k++;
        arr3->length++;
    }
    for(;j<arr2.length;j++){
        arr3->A[k] = arr2.A[j];
        k++;
        arr3->length++;
    }

    // arr3->length = arr2.length + length;

    return arr3;
}
Array* Array::setUnionForUnsortedList(Array arr2)
{
    Array *arr3 = new Array(size + arr2.size);
    int i,j,k;
    k=0;

    for(i=0;i<length;i++){
        int found = false;
        for(j=0;j<length;j++){
            if(A[i] == arr2.A[j]){
                found = true;      
            }
        }
        if(!found){
            arr3->A[k] = A[i];
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
Array* Array::setIntersection(Array arr2)
{
    Array *arr3 = new Array(size+arr2.size);
    int i,j,k;
    i=j=k=0;

    while(i<length && j<arr2.length){
        if(A[i] == arr2.A[j]){
            arr3->A[k] = A[i];
            j++;
            i++;
            k++;
        }else if(A[i] < arr2.A[j]){
            i++;
        }else{
            j++;
        }
        
    }

    arr3->length = k;

    return arr3;
}
Array* Array::setIntersectionForUnsortedList(Array arr2)
{
    Array *arr3 = new Array(size+arr2.size);
    int i,j,k;
    k=0;

    for(i=0;i<length;i++){
        for(j=0;j<arr2.length;j++){
            if(A[i] == arr2.A[j]){
                arr3->A[k++] = A[i];
                arr3->length++;
            }
        }
    }

    return arr3;
}
//A-B   (A minus B)
Array* Array::setDifference(Array arr2)
{
    Array *arr3 = new Array(size + arr2.size);
    int i,j,k;
    i=j=k=0;

    while(i<length && j<arr2.length){
        if(A[i] == arr2.A[j]){
            i++;
            j++;
        }else if(A[i] < arr2.A[j]){
            arr3->A[k++] = A[i++];
            arr3->length++;
        }else{
            j++;
        }
    }
    for(;i<length;i++){
        arr3->A[k++] = A[i];
        arr3->length++;
    }

    return arr3;
}
//A-B
Array* Array::setDifferenceForUnsortedList(Array arr2)
{
    Array *arr3 = new Array(size + arr2.size);
    int i,j,k;
    k=0;

    for(i=0;i<length;i++){
        int found = false;
        for(j=0;j<arr2.length;j++){
            if(A[i] == arr2.A[j]){
                found = true;
            }
        }
        if(!found){
            arr3->A[k++] = A[i];
            arr3->length++;
        }
    }

    return arr3;
}

int main(){
    Array *arr = new Array(10);
    arr->append(3);
    arr->append(5);
    arr->append(7);
    arr->append(9);

    arr->display();

    return 0;    
}