#include <iostream>

using namespace std;

struct Stack
{
    int size;
    int top;
    int *s;
};

int isFull(struct Stack st)
{
    if(st.top == st.size - 1)
        return true;
    else    
        return false;
}

int isEmpty(struct Stack st)
{
    if(st.top==-1)
        return 1;
    else
        return 0;
}

void push(struct Stack *st, int value)
{
    if(!isFull(*st))
        st->s[++st->top]=value;
    else    
        cout<<"Stack overflow"<<endl;
}

void display(struct Stack st)
{
    int i;
    for(i=st.top;i>-1;i--)
        cout<<st.s[i]<<" ";
    cout<<endl;
}

int pop(struct Stack *st)
{
    int x=-1;
    if(!isEmpty(*st))
        return x=st->s[st->top--];
    else    
        cout<<"Stack underflow"<<endl;

    return x;
}

int stackTop(struct Stack st)
{
    if(!isEmpty(st))
        return st.s[st.top];
    else
        return -1;
}

int main()
{
    int i,x;
    struct Stack myStack;
    cout<<"Enter size ";
    cin>>myStack.size;
    myStack.s = new int[myStack.size];
    myStack.top = -1;

    for(i=0;i<myStack.size;i++)
    {
        cout<<"Enter Value no. "<<i+1<<" - ";
        cin>>x;
        push(&myStack, x);
    }

    display(myStack);
    cout<<pop(&myStack)<<endl;
    cout<<pop(&myStack)<<endl;
    //cout<<pop(&myStack)<<endl;

    cout<<stackTop(myStack)<<endl;

    return 0;
}