#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node * createCircularList(int *A, int n, struct Node *cl)
{
    int i;
    struct Node *tail = NULL;
    if(cl->next != NULL){
        cout<<"please supply empty first node"<<endl;
        return NULL;
    }

    for(i=0;i<n;i++)
    {
        if(i==0){
            cl->data = A[i];
            cl->next = NULL;
            tail = cl;
        }else{
            struct Node *p = new Node;
            p->data = A[i];
            tail->next = p;
            tail = p;
        }
    }
    tail->next = cl;
    return cl;
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

struct Node *globalList = NULL;
void displayCircularListUsingRecursion(struct Node *p)
{
    static int flag = 0;
    if(p != globalList || flag == 0){
        flag = 1;
        cout<<p->data<<" ";
        displayCircularListUsingRecursion(p->next);
    }
}

int main()
{
    struct Node *list = new Node;
    int A[5] = {3,5,7,9,11};
    globalList = createCircularList(A,5,list);
    displayCircularListUsingRecursion(globalList);
    cout<<endl;
    
    return 0;
}