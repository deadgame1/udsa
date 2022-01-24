#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node *globalList = NULL;
void createCircularList(int *A, int n)
{
    int i;
    struct Node *tail = NULL;
    globalList = new Node;

    globalList->data = A[0];
    globalList->next = globalList;
    tail=globalList;

    for(i=1;i<n;i++)
    {
        struct Node *p = new Node;
        p->data = A[i];
        p->next = tail->next;
        tail->next = p;
        tail = p;
    }
}

void displayCircularList(struct Node *head)
{
    struct Node *p = head;
    do
    {
        cout<<p->data<<" ";
        p = p->next;
    } while (p != head);
    cout<<endl;
}

void displayCircularListUsingRecursion(struct Node *p)
{
    static int flag = 0;
    if(p != globalList || flag == 0){
        flag = 1;
        cout<<p->data<<" ";
        displayCircularListUsingRecursion(p->next);
    }
    flag = 0;
}

int length(struct Node *p)
{
    int count = 0;
    if(p==NULL)
    {
        return count;
    }
    struct Node *t = p;
    do
    {
        count++;
        t = t->next;
    } while (t != p);

    return count;
}

void insert(int position, int value)
{
    int i;
    struct Node *p = globalList, *t = new Node;
    t->data = value;
    if(position < 0 || position > length(p))
        return;
    if(position == 0)
    {
        if(globalList == NULL){
            globalList = t;
            globalList->next = globalList;
        }
        else
        {
            while(p->next != globalList)
                p = p->next;
            p->next = t;
            t->next = globalList;
            globalList = t;
        }
    }else{
        for(i=0;i<position-1;i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    int A[5] = {3,5,7,9,11};
    createCircularList(A,5);
    displayCircularList(globalList);
    //insert(1,4);
    //insert(2,8);
    //insert(3,12);
    //insert(4,16);
    insert(0,20);

    displayCircularList(globalList);
    //cout<<length(globalList);

    return 0;
}