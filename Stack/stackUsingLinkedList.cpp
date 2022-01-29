#include <iostream>

using namespace std;

class Node
{
    private:
        int data;
    public:
        Node *next;
        Node(int x, Node *p)
        {
            this->data=x;
            if(p != NULL)
                this->next= p;
            else            
                this->next=NULL;
        };
        int getData()
        {
            return this->data;
        }
};

class stackLL
{
private:
    /* data */
    Node *top;
public:
    stackLL()
    {
        this->top=NULL;
    };
    stackLL(Node *p);
    ~stackLL();
    void push(int x);
    void display();
};

stackLL::stackLL(Node *p)
{
    this->top=p;
}

stackLL::~stackLL()
{
    delete this->top;
}

void stackLL::push(int x)
{
    Node *p = new Node(x,this->top);
    //&Node(x,this->top);
    if(p == NULL)
        cout<<"Stack overflow"<<endl;
    this->top=p;
}

void stackLL::display()
{
    Node *p=this->top;
    while(p)
    {
        cout<<p->getData()<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    stackLL myStack = stackLL();
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.display();
    
    return 0;
}