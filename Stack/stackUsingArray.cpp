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

void push(struct Stack *st, int value)
{
    if(!isFull(*st))
        st->s[++st->top]=value;
}

int main()
{
    int i,x;
    struct Stack myStack;
    cout<<"Enter size";
    cin>>myStack.size;
    myStack.s = new int[myStack.size];
    myStack.top = -1;

    for(i=0;i<myStack.size;i++)
    {
        cout<<"Enter Value no. "<<i+1<<" -";
        cin>>x;
        push(&myStack, x);
    }

    return 0;
}