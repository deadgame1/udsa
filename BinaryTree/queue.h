#include <iostream>

using namespace std;

template <class T>
class TreeNode
{
public:
    TreeNode* lchild;
    T data;
    TreeNode* rchild;
};

template <class t1>
class Node
{
    public:
        t1 data;
        Node *next;
        Node()
        {
            data=NULL;
            next=NULL;
        }
};

template <class t>
class QueueLL
{
    public:
        Node<t>* front;
        Node<t>* rear;
        QueueLL()
        {
            front=rear=NULL;
        };
        void enqueue(t x)
        {
            Node<t>* p=new Node<t>;
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
        t dequeue()
        {
            t x=NULL;   
            Node<t> *p=new Node<t>;
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
            Node<t>* p=new Node<t>;
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
            Node<t> *p=front;
            while(p)
            {
                cout<<p->data<<" ";
                p=p->next;
            }
            cout<<endl;
        }
};


// int main()
// {
//     QueueLL<int> myQueue = QueueLL<int>();
//     myQueue.enqueue(3);
//     myQueue.enqueue(5);
//     myQueue.enqueue(7);
//     myQueue.display();
//     myQueue.dequeue();
//     myQueue.display();

//     return 0;
// }
