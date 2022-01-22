#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

//global pointers
struct Node *first=NULL; 
struct Node *last=NULL; 

void create(int A[],int n)
{
    int i;
    struct Node *newNode;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last=first;
    for(i=1;i<n;i++)
    {
      newNode = new Node;
      newNode->data = A[i];
      newNode->next = NULL;
      last->next = newNode;
      last=newNode;  
    }
}

void display(struct Node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

/**
 * @brief Recursive display fn for LinkedList, Tail Recursion
 * 
 */
void Rdisplay(struct Node *p){
    if(!p) return;
    cout<<p->data<<endl;
    Rdisplay(p->next);
}

/**
 * @brief printing in reverse
 * 
 */
void ReverseDisplay(struct Node *p){
    if(!p) return;
    ReverseDisplay(p->next);
    cout<<p->data<<endl;
}

int count(struct Node *p){
    int count = 0;
    while(p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int Rcount(struct Node *p)
{
    int count = 0;
    if(!p) return 0;
    return Rcount(p->next)+1;
}

int sumOfAllElements(struct Node *p)
{
    int sum = 0;
    while(p)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

int RsumOfAllElements(struct Node *p)
{
    int sum = 0;
    if(!p) return 0;
    return RsumOfAllElements(p->next) + p->data;
}

int maxElement(struct Node *p)
{
    int max = INT16_MIN;
    while(p)
    {
        if(p->data > max) max = p->data;
        p = p->next;
    }
    return max;
}

/**
 * @brief Any Iterative function can be easily converted to Tail recursion.
 * this is what I have done below with the original iterative function "maxElement"
 * 
 * @param p 
 * @return int 
 */
int RmaxElement(Node *p)
{
    static int max = INT16_MIN;
    if(!p) return max;
    if(p->data > max) max = p->data;
    if(p->next){
        RmaxElement(p->next);
    }
    return max;
}

/**
 * @brief this is kind of head recursion.
 * if you draw or imagine the tracing tree, the comparisons are done from last to first in order to find max
 * in RmaxElement the comparisons were done top to bottom.
 * 
 * @param p 
 * @return int 
 */
int RmaxElement2(Node* p)
{
    int x = 0;
    if(!p)
    {
        return INT16_MIN;
    }else{
        x = RmaxElement2(p->next);
        if(x > p->data){
            return x;
        }else{
            return p->data;
        }
    }
}

/**
 * @brief please note even though a pointer is the formal paramater, and the actual parameter is first
 * this is not call by address, this is call by value. first pointer's copy is made to "p"
 * to confirm this you can check the addresses of first and of p's address at the beginning of the function and at the end.
 * 
 * @param p 
 * @return int 
 */
int minElement(struct Node *p)
{
    int min = INT16_MAX;
    //cout<<p->next<<endl;
    while(p)
    {
        if(p->data < min) min = p->data;
        p = p->next;
    }
    //cout<<p->next<<endl; //p will point to 0/NULL and stmt will lead to segmentation fault
    return min;
}

Node * linearSearch(Node *p, int key)
{
    while(p)
    {
        if(p->data == key) return p;
        p = p->next;
    }
    return NULL;
}

Node * RlinearSearch(Node *p, int key)
{
    if(p == NULL) return NULL;
    
    if(p->data == key) return p;

    RlinearSearch(p->next,key);

    return NULL;
}

/**
 * @brief improved linear search by "Move to Head" strategy
 * 
 * @param p 
 * @param key 
 * @return struct Node* 
 */
struct Node * ImprovedLinearSearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while(p)
    {
        if(p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }

    return NULL;
}

/**
 * @brief Insert a value at a given position in the linked list
 * 
 * @param position 
 * @param value 
 */
void insert(int position,int value)
{
    struct Node * t;
    int listLength = count(first);
    if(position < 0 || position > listLength){
        cout<<"invalid index provided for insertion"<<endl;
        return;
    }
    t=new Node;
    t->data = value;
    
    if(position == 0)
    {
        t->next = first;
        first = t; 
    }else if(position > 0)
    {
        struct Node *p = first;
        int i;
        for(i=0;i<position-1 && p;i++)
        {
            p = p->next;
        }
        if(p)
        {
            t->next = p->next;
            p->next = t; 
            if(position == listLength){
                last = t;
            }
        }
    }
}

void insertLast(int value)
{
    struct Node* t = new Node;
    t->data = value;
    t->next = NULL;
    if(!first)
    {
        first = last = t;
    }else{
        last->next = t;
        last = t;
    }
}

/**
 * @brief assuming list is sorted in ascending manner,
 * 
 * @param value 
 */
void insertInASortedList(int value)
{   
    struct Node *p = first;
    struct Node *t = new Node;
    bool insertionDone = false;
    t->data = value;
    if(first == NULL)
    {
        first = last = t;
    }else if(t->data < p->data)
    {
        t->next = p;
        first = t;
    }else{
        while(p->next)
        {
            if(value < p->next->data){
                t->next = p->next;
                p->next = t;
                insertionDone = true;
                break;
            }
            p = p->next;
        }
        if(!insertionDone)
        {
            insertLast(value);
            delete t,p;
        }
    }
}
int main()
{
    //int A[] = {3,5,7,9,11,13};
    //int A[] = {1};
    //create(A,0);
    //struct Node *result;
    // result = ImprovedLinearSearch(first,13);
    // if(result)
    //     cout<<"Key is found - "<<result->data<<endl;
    // else    
    //     cout<<"Key not found \n";

    struct Node * tempVar;
    //display(first);

    // insertLast(3);
    // insertLast(5);
    // insertLast(7);
    // insertLast(9);
    // insertLast(11);
    // insertInASortedList(10);
    // insertInASortedList(200);
    insertInASortedList(8);
    insertInASortedList(5);
    //tempVar = insert(3,2);
    
    display(first);

    return 0;
}
