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
    void display()
    {   
        if(front==rear)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        int i;
        for(i=front+1;i<=rear;i++)
            cout<<Q[i]<<" ";
        cout<<endl;
    };
};

int main()
{
    Queue myQ=Queue(4);
    myQ.enqueue(3);
    myQ.enqueue(5);
    myQ.enqueue(7);
    myQ.enqueue(9);
    myQ.dequeue();
    myQ.display();

    return 0;
}