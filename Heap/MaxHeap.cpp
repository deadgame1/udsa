#include <iostream>

using namespace std;

template <class T>
class MaxHeap
{
private:
    
public:
    int *A;
    int tail;
    int size;
    MaxHeap(int n, int array[])
    {
        size=n+1;
        A = new int[size]; 
        int i;
        A[0]=0;
        A[1]=array[0];
        tail=1;
        for(i=1;i<n;i++)
        {
            insertInHeap(array[i]);
        }   
    };
    void insertInHeap(int element)
    {
        tail++;
        if(tail >= size)
        {
            tail--;
            cout<<"Heap full"<<endl;
            return;
        }
        int i=tail;
        while(i > 1 && element > A[i/2])
        {
            A[i] = A[i/2];
            i = i/2;
        }
        A[i] = element;
    }
    void deleteInHeap()
    {
        if(tail == 0)
        {
            cout<<"Heap empty"<<endl;
            return;
        }
        int temp = A[1];
        A[1] = A[tail];
        tail--;
        
        int i=1;
        int j=2*i;
        
        while(j <= tail)
        {
            if(A[j] < A[j+1])
                j=j+1;
            if(A[i]<A[j])
            {
                swap(&A[i],&A[j]);
                i = j;
                j = 2*i;
            }
            else
                break;
        }
        cout<<temp<<" deleted"<<endl;
        A[tail+1] = temp; //storing deleted element
    };
    void swap(int *x, int *y)
    {
        int temp;
        temp = *x;
        *x=*y;
        *y=temp;
    }
};

int main()
{
    int myArr[] = {15,5,20,30,60,10,25,45};
    MaxHeap<int> myHeap = MaxHeap<int>(8,myArr);

    for(int i=1;i<myHeap.size;i++)
    {
        cout<<myHeap.A[i]<<" ";
    }
    cout<<endl;

    for(int j=0;j<=sizeof(myArr)/sizeof(myArr[0]);j++)
    {
        myHeap.deleteInHeap();
    }
    
    for(int i=1;i<myHeap.size;i++)
    {
        cout<<myHeap.A[i]<<" ";
    }
    cout<<endl;

    return 0;
}