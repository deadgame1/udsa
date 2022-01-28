#include <iostream>

using namespace std;

struct Stack
{
    int size;
    int top;
    int *s;
};

void push(struct Stack *st, int value)
{
    
}

int isFull(struct Stack *st)
{
    if(st->top == st->size - 1)
        return true;
    else    
        return false;
}

int main()
{
    struct Stack myStack;
    cout<<"Enter size";
    cin>>myStack.size;
    myStack.s = new int[myStack.size];
    myStack.top = -1;

    return 0;
}