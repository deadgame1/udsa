#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};



void createCircularList(int *A, int n, struct Node *cl)
{
    int i;
    struct Node *head = cl, *first = NULL, *tail = NULL;
    if(cl->next != NULL){
        cout<<"please supply empty HEAD node"<<endl;
    }

    for(i=0;i<n;i++)
    {
        struct Node *p = new Node;
        p->data = A[i];
        if(i==0){
            head->next = p;
            tail = first = p;
        }else if(i==n-1){
            tail->next = p;
            p->next = first;
        }else{
            tail->next = p;
            tail = p;
        }
    }
}

int main()
{
    struct Node *circularList = new Node;
    circularList->next = NULL;
    int A[5] = {3,5,7,9,10};
    createCircularList(A,5,circularList);

    return 0;
}