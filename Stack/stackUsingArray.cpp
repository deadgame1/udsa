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
    {
        st->s[++st->top]=value;
    }
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
    {    
        x=st->s[st->top--];
        return x;
    }
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

int peek(struct Stack st, int position)
{
    if(position < 1 || position > st.size)
    {
        cout<<"Invalid Index"<<endl;
        return -1;
    }

    return st.s[st.top-position+1];
}

void create(struct Stack *st)
{
    int i,x;
    cout<<"Enter size ";
    cin>>st->size;
    st->top = -1;
    st->s = new int[st->size];
    for(i=0;i<st->size;i++)
    {
        cout<<"Enter Value no. "<<i+1<<" - ";
        cin>>x;
        push(st, x);
    }
}

int main()
{
    int i,x;
    struct Stack myStack;
    create(&myStack);
    display(myStack);
    //cout<<pop(&myStack)<<endl;
    //cout<<pop(&myStack)<<endl;
    //cout<<pop(&myStack)<<endl;

    //cout<<stackTop(myStack)<<endl;

    //cout<<peek(myStack,3)<<endl;

    return 0;
}