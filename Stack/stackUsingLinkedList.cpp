#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;
template <class T>
class Node
{
    private:
        T data;
    public:
        Node *next;
        Node()
        {
            this->next=NULL;
        };
        Node(T x, Node *p)
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
template <class B>
class stackLL
{
private:
    /* data */
public:
    Node<B> *top;
    stackLL()
    {
        this->top=NULL;
    };
    stackLL(Node<B> *p);
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
stackLL<B>::stackLL(Node<B> *p)
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
    Node<B> *p = new Node<B>(x,this->top);
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
        return -1;
    }
    Node<B> *p=this->top;
    B x = this->top->getData();
    this->top=this->top->next;
    delete p;

    return x;
}

template <class B>
void stackLL<B>::display()
{
    Node<B> *p=this->top;
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
    Node<B> *p = new Node<B>();
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
    Node<B> *p=this->top;
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

int checkParenthesis(stackLL<char> stk, string str)
{
    int i;
    char x;
    for(i=0;i<str.length() && str[i] != '\0';i++)
    {
        if(str[i]=='(')stk.push('(');
        else if(str[i]=='[')stk.push('[');  
        else if(str[i]=='{')stk.push('{');  
        else if(str[i]==')' || str[i]==']' || str[i]=='}')
        {
            if(stk.isEmpty()) return 0;
            x=stk.pop();
            if(str[i]==')' && x != '(') return 0;
            if(str[i]==']' && x != '[') return 0;
            if(str[i]=='}' && x != '{') return 0;
        }
    }

    return stk.isEmpty() ? 1 : 0;  
}


int isOperator(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='!' || x=='(' || x==')')
        return 1;
    else 
        return 0;
}

int operatorPrecedence(char x, int outStack=1)
{
    if(x=='+' || x=='-') 
        return outStack==1 ? 1 : 2;
    if(x=='*' || x=='/') 
        return outStack==1 ? 3 : 4;
    if(x=='^') 
        return outStack==1 ? 6 : 5;
    if(x=='(') 
        return outStack==1 ? 7 : 0;
    if(x==')') return 0;
    return 8;
}

char * infixToPostfix(char *infix, stackLL<char> stk)
{
    char * postfix = new char[strlen(infix) + sizeof(char)*1];
    stk.top=NULL;
    int i=0;
    int j=0;
    char x;
    while(infix[i]!='\0')
    {
        if(stk.isEmpty())
            stk.push(infix[i++]);
        else
        {
            x=stk.stackTop();
            if(operatorPrecedence(infix[i]) > operatorPrecedence(x,2))
                stk.push(infix[i++]);
            else if(operatorPrecedence(infix[i]) == operatorPrecedence(x,2))
            {   stk.pop(); 
                i++;
                //only in the case of opening and closing brackets precedence will be equal and we will not print () it to output.
            }
            else
                postfix[j++] = stk.pop();
        }   
    }
    while(!stk.isEmpty())
        postfix[j++]=stk.pop();
    //postfix[j] = '\0';

    return postfix;
}

int evaluatePostfix(char *postfix)
{
    int result=-1;
    stackLL<int> stk=stackLL<int>();
    int i=0,operandA,operandB,tempResult;
    while(postfix[i]!='\0')
    {
        if(isOperator(postfix[i]))
        {
            operandB=stk.pop();
            operandA=stk.pop();
            switch (postfix[i])
            {
            case '+':
                tempResult=operandA+operandB;
                break;
            case '-':
                tempResult=operandA-operandB;
                break;
            case '*':
                tempResult=operandA*operandB;
                break;
            case '/':
                tempResult=operandA/operandB;
                break;
            case '^':
                tempResult=pow(operandA,operandB);
                break;
            default:
                break;
            }
            stk.push(tempResult);
            i++;
        }
        else
        {
            stk.push(postfix[i++] - '0');
        }
    }

    return result=stk.pop();
}
int main()
{
    stackLL<char> myStack = stackLL<char>();
    //char input[] = "a^b^c"; //abc^^
    //char input[] = "(a+b)*c-d^e^f";
    char input[] = "(3+5)*6-2^2^2";
    //char input[] = "234*+82/-";
    char *output = infixToPostfix(input, myStack);
    int result = evaluatePostfix(output);
    cout<<result<<endl;

    // stackLL<char> myStack = stackLL<char>();
    // myStack.push('a');
    // myStack.pop();
    // cout<<myStack.pop();
    //myStack.display();

    //string A="{[]([]}";
    //cout<<"Enter expression"<<endl;
    //cin>>A;
    // int result = checkParenthesis(myStack,A);
    // if(result==1)
    //     cout<<"Parenthesis match"<<endl;
    // else    
    //     cout<<"Parenthesis dont match"<<endl;

    //cout<<myStack.pop()<<endl;
    //cout<<myStack.pop()<<endl;
    //cout<<myStack.pop()<<endl;
    //cout<<myStack.peek(2)<<endl;

    //myStack.display();

    return 0;
}