#include <iostream>
//#include "chains.h"

struct Node{
    int data;
    struct Node* next;
};

void insertInASortedList(struct Node** first, int value)
{   
    struct Node *p = *first;
    struct Node *t = new Node;
    bool insertionDone = false;
    t->data = value;
    if(((*first) == NULL))
    {
        *first = t;
    }else if(t->data < (*first)->data)
    {
        t->next = *first;
        *first = t;
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
            p->next = t;
            t->next = NULL;
            //insertLast(value); //handles reassignment of last pointer properly instead of manuall doing it again here.
            //delete t,p;
        }
    }
}

int hashingFn(int key){
    return key%10;
}
void insert(struct Node* H[], int key){
    int index = hashingFn(key);
    insertInASortedList(&H[index],key);

}
int main(){
    struct Node *HT[10];
    
    for(int i=0;i<10;i++)
        HT[i]=NULL;
    
    insert(HT,12);
    insert(HT,22);
    insert(HT,32);
    insert(HT,2);

    return 0;
}
