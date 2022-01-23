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
 * handles the edge case if list is empty
 * also handles if the given value is less than first node.
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
            insertLast(value); //handles reassignment of last pointer properly instead of manuall doing it again here.
            delete t,p;
        }
    }
}

/**
 * @brief deletes the element at the given position and returns the element deleted.
 * handles edge cases when list is empty or index is out of bounds
 * 
 * @param position 
 * @return int 
 */
int deletePosition(int position)
{
    int x,i;
    x=-1;
    struct Node *p, *t;
    int length = count(first);
    p = first;
    t = NULL; //tailing pointer

    if(!first){
        cout<<"list is empty";
        return x;
    }

    if(position < 1 || position > length){
        return x;
    }

    if(position == 1)
    {
        first = first->next;
        x = p->data;
        delete p;
    }else{
        for(i=0;i<position-1;i++)
        {
            t = p;
            p = p->next;
        }
        t->next = p->next;
        x = p->data;
        delete p;
    }

    return x;
}

/**
 * @brief checks if list is in the ascending order or not.
 * 
 * @return true 
 * @return false 
 */
bool checkListSorted()
{
    int x = -65536;
    struct Node *p = first;

    while(p){
        if(x > p->data)
        {
            return false;
        }
        x = p->data;
        p = p->next;
    }
    
    return true;
}

void removeDuplicatesInSorted()
{
    if(false == checkListSorted() || first == NULL || 1 == count(first))
    {
        return;
    }

    struct Node *p = first;
    struct Node *q = p->next;

    while(q){
        if(p->data == q->data){
            p->next = q->next;
            delete q;
            q = p->next;
        }else{
            p = q;
            q = q->next;
        }
    }
}

/**
 * @brief reversing a list using Auxillary array.
 * 
 */
void reverseListUsingAux()
{
    int listLength = count(first);
    if(first == NULL || listLength == 1){
        return;
    }
    int i=0;
    int *A = new int[listLength];
    struct Node * p = first;
    while(p)
    {
        A[i++] = p->data;
        p = p->next;
    }
    i--;
    p = first;
    while(i >=0)
    {
        p->data = A[i--];
        p = p->next;
    }
}

void reverseUsingSlidingPointers()
{
    if(first == NULL || count(first) == 1){
        return;
    }
    struct Node *p, *q, *r;
    p = last = first;
    q = r = NULL;
    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

/**
 * @brief //dont forget to last = first, before calling this fn so that last is pointing to last node.
 * 
 * @param t 
 * @param p 
 */
void reverseUsingRecursion(struct Node *t, struct Node *p)
{
    if(p)
    {
        reverseUsingRecursion(p, p->next);
        p->next = t;
    }else{
        first = t;
    }
}

/**
 * @brief Just concatenate 2 lists, (different from merging - in which 2 sorte lists are combine to get 1 sorted lists)
 * this is just concatenate. 
 * 
 * @param one 
 * @param two 
 * @return struct Node* 
 */
struct Node * concatenateLists(struct Node *one, struct Node * two)
{
    struct Node * first = one;
    struct Node * second = two;
    if(!one && !two){
        return NULL;
    }
    if(!one){
        return two;
    }
    if(!two){
        return one;
    }
    while(first->next){
        first = first->next;
    }
    first->next = two;
    return one;
}

void insertLastInAList(struct Node** p, int value)
{
    struct Node* t = new Node;
    struct Node *c = *p;
    t->data = value;
    t->next = NULL;
    if(!(*p))
    {
        *p = t;
    }else{
        while((c)->next)
        {
            c = (c)->next;
        }
        (c)->next = t;
    }
}

struct Node * merge2Lists(struct Node *one, struct Node *two)
{
    struct Node *three = NULL, *lastOfThree = NULL;

    if(!one && !two)
    {
        return NULL;
    }
    if(!one)
    {
        return two;
    }
    if(!two)
    {
        return one;
    }

    if(one->data < two->data)
    {
        three = lastOfThree = one;
        one = one->next;
        three->next = NULL;
    }else{
        three = lastOfThree = two;
        two = two->next;
        three->next = NULL;
    }

    while(one && two)
    {
        if(one->data < two->data){
            lastOfThree->next = one;
            lastOfThree = one;
            one = one->next;
        }else{
            lastOfThree->next = two;
            lastOfThree = two;
            two = two->next;
        }
        lastOfThree->next = NULL;
    }

    if(one) 
        lastOfThree->next = one;
    else
        lastOfThree->next = two;   

    return three;
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
    //struct Node * tempVar;
    //display(first);

    struct Node *one = NULL;
    insertLastInAList(&one,2);
    insertLastInAList(&one,4);
    insertLastInAList(&one,6);
    insertLastInAList(&one,8);
    display(one);
    struct Node *two = NULL;
    insertLastInAList(&two,1);
    insertLastInAList(&two,3);
    insertLastInAList(&two,5);
    insertLastInAList(&two,7);
    insertLastInAList(&two,9);   
    display(two);

    struct Node * third = merge2Lists(one,two);
    display(third);

    // reverseUsingRecursion(NULL,first); //dont forget to last = first, before calling this fn

    return 0;
}
