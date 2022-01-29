#include <iostream>

using namespace std;

class Node
{
    private:
        int data;
    public:
        Node *next;
        Node()
        {
            this->next=NULL;
        };
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
    int pop();
    int isFull();
    int isEmpty();
    int peek(int position);
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
    if(p == NULL)
        cout<<"Stack overflow"<<endl;
    else
        this->top=p;
}

int stackLL::pop()
{
    if(this->top == NULL)
    {   
        cout<<"Stack underflow"<<endl;
        return -1;
    }
    Node *p=this->top;
    int x = this->top->getData();
    this->top=this->top->next;
    delete p;

    return x;
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

int stackLL::isFull()
{
    Node *p = new Node();
    if(p == NULL)
        return 1;
    return 0;
}

int stackLL::isEmpty()
{
    return this->top == NULL ? 1 : 0;
}

int stackLL::peek(int position)
{
    int i;
    Node *p=this->top;
    for(i=0;i<position-1 && p!=NULL;i++)
        p=p->next;
    if(p)
        return p->getData();
    return -1;

}

int checkParenthesis(stackLL stk, string stringToBeChecked)
{
    int i,x;
    for(i=0;i<stringToBeChecked.length();i++)
    {
        if(stringToBeChecked[i] == '(')
        {
            stk.push(1);
        }
        else if(stringToBeChecked[i] == ')')
        {
            x = stk.pop();
            if(x==-1)
                return 0;
        }
    }

    if(stk.isEmpty() == 1)
        return 1;
    else
        return 0;        
}
int main()
{
    stackLL myStack = stackLL();
    //myStack.push(10);
    //myStack.push(20);
    //myStack.push(30);
    //myStack.display();

    string A;
    cout<<"Enter expression"<<endl;
    cin>>A;
    int result = checkParenthesis(myStack,A);
    if(result==1)
        cout<<"Parenthesis match"<<endl;
    else    
        cout<<"Parenthesis dont match"<<endl;

    //cout<<myStack.pop()<<endl;
    //cout<<myStack.pop()<<endl;
    //cout<<myStack.pop()<<endl;
    //cout<<myStack.peek(2)<<endl;

    //myStack.display();

    return 0;
}