#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;
template <class T>
class StackNode
{
    private:
        T data;
    public:
        StackNode *next;
        StackNode()
        {
            this->next=NULL;
        };
        StackNode(T x, StackNode *p)
        {
            this->data=x;
            if(p != NULL)
                this->next= p;
            else            
                this->next=NULL;
        };
        T getData()
        {
            return this->data;
        }
};

// template <class T1>
// class TreeNode
// {
// public:
//     TreeNode* lchild;
//     T1 data;
//     TreeNode* rchild;
// };

template <class B>
class stackLL
{
private:
    /* data */
public:
    StackNode<B> *top;
    stackLL()
    {
        this->top=NULL;
    };
    stackLL(StackNode<B> *p);
    ~stackLL();
    void push(B x);
    void display();
    B pop();
    int isFull();
    int isEmpty();
    B peek(int position);
    B stackTop();
};

template <class B>
stackLL<B>::stackLL(StackNode<B> *p)
{
    this->top=p;
}

template <class B>
stackLL<B>::~stackLL()
{
    delete this->top;
}

template <class B>
void stackLL<B>::push(B x)
{
    StackNode<B> *p = new StackNode<B>(x,this->top);
    if(p == NULL)
        cout<<"Stack overflow"<<endl;
    else
        this->top=p;
}

template <class B>
B stackLL<B>::pop()
{
    if(this->top == NULL)
    {   
        cout<<"Stack underflow"<<endl;
        //return -1;
        return NULL;
    }
    StackNode<B> *p=this->top;
    B x = this->top->getData();
    this->top=this->top->next;
    delete p;

    return x;
}

template <class B>
void stackLL<B>::display()
{
    StackNode<B> *p=this->top;
    while(p)
    {
        cout<<p->getData()<<" ";
        p=p->next;
    }
    cout<<endl;
}

template <class B>
int stackLL<B>::isFull()
{
    StackNode<B> *p = new StackNode<B>();
    if(p == NULL)
        return 1;
    return 0;
}

template <class B>
int stackLL<B>::isEmpty()
{
    return this->top == NULL ? 1 : 0;
}

template <class B>
B stackLL<B>::peek(int position)
{
    int i;
    StackNode<B> *p=this->top;
    for(i=0;i<position-1 && p!=NULL;i++)
        p=p->next;
    if(p)
        return p->getData();
    return -1;

}

template <class B>
B stackLL<B>::stackTop()
{
    if(!this->isEmpty())
        return this->top->getData();
    else    
        return -1;
}

// int main()
// {
//     stackLL<char> myStack = stackLL<char>();
//     myStack.push('a');
//     myStack.pop();
//     cout<<myStack.pop();
//     myStack.display();

//     //myStack.display();

//     return 0;
// }