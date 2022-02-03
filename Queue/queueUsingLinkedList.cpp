#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node()
        {
            data=NULL;
            next=NULL;
        }
};

class QueueLL
{
    public:
        Node* front;
        Node* rear;
        QueueLL()
        {
            front=rear=NULL;
        };
        void enqueue(int x)
        {
            Node* p=new Node;
            if(p==NULL)
            {
                cout<<"Queue is full"<<endl;
                return;
            }    
            p->data=x;
            p->next=NULL;
            if(isEmpty())
                front=rear=p;
            else
            {
                rear->next=p;
                rear=p;
            }
        };   
        int dequeue()
        {
            int x=-1;   
            Node *p=new Node;
            if(isEmpty())
            {
                cout<<"Queue is empty"<<endl;
                return x;
            }
            
            x=front->data;
            p=front;
            if(front->next == NULL)
            {
                front=rear=NULL; 
            }
            else
                front=front->next;

            delete p;

            return x;
        };
        int isFull()
        {
            Node* p=new Node;
            return p==NULL ? 1 : 0;
        };
        int isEmpty()
        {
            return front==NULL;
        };
        void display()
        {
            if(isEmpty())
                return;
            Node *p=front;
            while(p)
            {
                cout<<p->data<<" ";
                p=p->next;
            }
            cout<<endl;
        }
};


int main()
{
    QueueLL myQueue = QueueLL();
    myQueue.enqueue(3);
    myQueue.enqueue(5);
    myQueue.enqueue(7);
    myQueue.display();
    myQueue.dequeue();
    myQueue.display();
    myQueue.enqueue(9);
    myQueue.enqueue(11);
    myQueue.enqueue(13);
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.display();

    return 0;
}
