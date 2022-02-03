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
        front=rear=0;
        Q=new int[size];
    };
    void enqueue(int x)
    {
        if(isFull())
            cout<<"Queue is full"<<endl;
        else
        {
            rear=(rear+1)%size;
            Q[rear]=x;
        }    
    };
    int dequeue()
    {
        int x=-1;
        int position;
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            position=(front+1)%size;
            x=Q[position];
            Q[position]=NULL;
            front=position;
        }
        return x;
    };
    void display()
    {   
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        int i=(front+1)%size;
        while(i!=(rear+1)%size)
        {
            cout<<Q[i]<<" ";
            i=(i+1)%size;
        }
        cout<<endl;
    };
    int isFull()
    {
        return (rear+1)%size==front;
    };
    int isEmpty()
    {
        return front==rear;
    }
    int first()
    {
        if(isEmpty())
        {   
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return Q[(front+1)%size];
    }
    int last()
    {
        if(isEmpty())
        {   
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return Q[rear];
    }
};

int main()
{
    Queue myQ=Queue(4);
    myQ.enqueue(3);
    myQ.enqueue(5);
    myQ.enqueue(7);
    myQ.dequeue();
    myQ.dequeue();
    myQ.enqueue(11);
    //myQ.enqueue(13);
    myQ.display();

    return 0;
}