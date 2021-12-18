#include <iostream>

using namespace std;  
template<class T>
class Array{
private:
    T *A;
    int size;
    int length;
    void swap(int *a, int *b);
public:
    Array(){
        size = 10;
        length = 0;
        A = new T[size];
    }
    Array(int sz){
        size = sz;
        length = 0;
        A = new T[size];
    }
    ~Array(){
        delete []A;
    }
    void display();
    void append(T x);
    void insert(T x,int index);
    T del(int index);
    T get(int index);
    void set(int index, T element);
    T min();
    T max();
    T sum();
    float avg(); //?return type ?
    void reverseWithAux();
    void reverse();
    void leftShift();
    void rightShift();
    void leftRotate();
    void rightRotate();
    int isSorted();
    Array<T>* merge(Array<T> arr2);
    Array<T>* setUnion(Array<T> arr2);
    Array<T>* setUnionForUnsortedList(Array<T> arr2);
    Array<T>* setIntersection(Array<T> arr2);
    Array<T>* setIntersectionForUnsortedList(Array<T> arr2);
    Array<T>* setDifference(Array<T> arr2);
    Array<T>* setDifferenceForUnsortedList(Array<T> arr2);
    int getLength(){
        return length;
    }
};

template<class T>
void Array<T>::display()
{
    if(length <=0){
        cout<<"Empty array"<<endl;
        return;
    }
    int i;
    cout<<"Elements of the array are - ";
    for(i=0; i<length; i++)
        if(i<length-1)
            cout<<A[i]<<" ";
        else
            cout<<A[i]<<endl;
}

template<class T>
void Array<T>::append(T x)
{
    if(length == size){
        return; //array full
    }
    A[length] = x;
    length++;
}

template<class T>
void Array<T>::insert(T x, int index)
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

template<class T>
T Array<T>::del(int index)
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

template<class T>
T Array<T>::get(int index)
{
    if(index >= 0 && index < length)
        return A[index];
    return -1;
}

template<class T>
void Array<T>::set(int index, T element)
{
    if(index >= 0 && index < length)
        A[index] = element;
}

template<class T>
T Array<T>::min()
{
    T min = A[0];
    for(int i=1;i<length;i++)
        if(A[i] < min)
            min = A[i];
    return min;
}

template<class T>
T Array<T>::max()
{
    T max = A[0];
    for(int i=1;i<length;i++)
        if(A[i] > max)
            max = A[i];
    return max;
}

template<class T>
T Array<T>::sum()
{
    T sum = 0;
    for(int i=0;i<length;i++)
        sum += A[i];
    return sum;
}

template<class T>
float Array<T>::avg()
{
    return sum()/length;
}

template<class T>
void Array<T>::reverseWithAux()
{
    int *B = new int[length]; //creating in heap , since the size of an array depends on function parameter. so it has to be dynamic and not static
    for(int i=length-1,j=0;i>=0;i--,j++){
        B[j] = A[i];
    }
    for(int i=0;i<length;i++){
        A[i] = B[i];
    }
}

template<class T>
void Array<T>::swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

template<class T>
void Array<T>::reverse()
{
    int temp;
    for(int i=0,j=length-1;i<j;i++,j--){
        // temp = arr->A[i];
        // arr->A[i] = arr->A[j];
        // arr->A[j] = temp;
        swap(&A[i],&A[j]);
    }
}

template<class T>
void Array<T>::leftShift()
{
    for(int i=1; i<length;i++){
        set(i-1, A[i]);
    }
    set(length-1, 0);
}

template<class T>
void Array<T>::rightShift()
{
    for(int i=length-2; i>=0;i--){
        set(i+1, A[i]);
    }
    set(0, 0);
}

template<class T>
void Array<T>::leftRotate()
{
    T first = A[0];
    for(int i=1; i<length;i++){
        set(i-1, A[i]);
    }
    set(length-1, first);
}

template<class T>
void Array<T>::rightRotate()
{
    T last = A[length-1];
    for(int i=length-2; i>=0;i--){
        set(i+1, A[i]);
    }
    set(0, last);
}

template<class T>
int Array<T>::isSorted()
{
    for(int i=0;i<length-1;i++){
        if(A[i] > A[i+1]){
            return 0;
        }
    }
    return 1;
}

//merges 2 sorted array and returns the result
template<class T>
Array<T>* Array<T>::merge(Array<T> arr2)
{
    Array<T> *arr3 = new Array<T>(length + arr2.length); 
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

template<class T>
Array<T>* Array<T>::setUnion(Array<T> arr2)
{
    Array<T> *arr3 = new Array<T>(size + arr2.size);
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

template<class T>
Array<T>* Array<T>::setUnionForUnsortedList(Array<T> arr2)
{
    Array<T> *arr3 = new Array<T>(size + arr2.size);
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

template<class T>
Array<T>* Array<T>::setIntersection(Array<T> arr2)
{
    Array<T> *arr3 = new Array<T>(size+arr2.size);
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

template<class T>
Array<T>* Array<T>::setIntersectionForUnsortedList(Array<T> arr2)
{
    Array<T> *arr3 = new Array<T>(size+arr2.size);
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
template<class T>
Array<T>* Array<T>::setDifference(Array<T> arr2)
{
    Array<T> *arr3 = new Array<T>(size + arr2.size);
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
template<class T>
Array<T>* Array<T>::setDifferenceForUnsortedList(Array<T> arr2)
{
    Array<T> *arr3 = new Array<T>(size + arr2.size);
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
    int sz;
    cout<<"Please enter size of array"<<endl;
    cin>>sz;
    Array<char> *arr = new Array<char>(sz);
    //arr->append(2);
    //arr->append(4);
    //arr->append(6);
    //arr->append(8);

    //Array<int> arr2(10);
    //arr2.append(3);
    //arr2->append(5);
    //arr2->append(7);
    //arr2->append(9);

    //Array *arr3 = arr->setUnion(*arr2);

    //arr3->display();

    //cout<<arr3->getLength()<<endl;

    int choice = 0;
    do{
        cout<<"Please enter your choice"<<endl;
        cout<<"1. Display"<<endl;
        cout<<"2. Append"<<endl;
        cout<<"3. Insert"<<endl;
        cout<<"4. Set"<<endl;
        cout<<"5. Get"<<endl;
        cout<<"6. Delete"<<endl;
        cout<<"7. Exit"<<endl;

        cin>>choice;
        char x; 
        int index;
        switch (choice)
        {
        case 1:
            arr->display();
            break;
        case 2:
            cout<<"Enter value to append"<<endl;
            cin>>x;
            arr->append(x);
            break;
        case 3:
            cout<<"Enter value to insert"<<endl;
            cin>>x;
            cout<<"Enter index at which to insert"<<endl;
            cin>>index;
            arr->insert(x,index);
            break;
        case 4:
            cout<<"Enter value to set"<<endl;
            cin>>x;
            cout<<"Enter index at which to set"<<endl;
            cin>>index;
            arr->set(index,x);
            break;
        case 5:
            cout<<"Enter index whose value is required"<<endl;
            cin>>index;
            cout<<arr->get(index)<<endl;
            break;
        case 6:
            cout<<"Enter index whose value is to be deleted"<<endl;
            cin>>index;
            arr->del(index);
            break;
        case 7:
            cout<<"Bye bye"<<endl;
            break;
        default:
            break;
        }
    }while(choice < 7);

    return 0;    
}