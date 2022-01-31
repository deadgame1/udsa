#include <iostream>

using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    Queue(int sz)
    {
        size=sz;
        front=rear=-1;
        Q=new int[size];
    };
    void enqueue(int x)
    {
        if(rear==size-1)
            cout<<"Queue is full"<<endl;
        else
        {
            rear++;
            Q[rear]=x;
        }    
    };
    int dequeue()
    {
        int x=-1;
        if(front==rear)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            x=Q[front+1];
            Q[front+1]=0;
            front++;
        }
        return x;
    };
};

int main()
{
    Queue myQ=Queue(7);
    myQ.enqueue(101);
    cout<<myQ.dequeue();

    return 0;
}