#include <iostream>

using namespace std;

class Node{
public:
    int key;
    Node *next;
    Node(int key, Node* next){
        this->key = key;
        this->next = next;
    }
};

int findMax(int list[], int sizeOfList){
    int max = list[0];
    for(int i=1;i<sizeOfList;i++){
        if(max<list[i])
            max = list[i];
    }

    return max;
}

/**
 * @brief inserting elements at end of list
 * 
 * @param n 
 * @param auxArray 
 * @param position 
 */
void insertNode(Node* n, Node* auxArray[], int position){
    if(auxArray[position] == NULL)
        auxArray[position] = n;
    else{
        Node* curr = auxArray[position];
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = n;
    }
}

void binBucketSort(int list[], int sizeOfList){
    int maxNumberInList = findMax(list,sizeOfList);
    // = new Node[maxNumberInList+1]
    Node **auxArray = new Node*[maxNumberInList+1];

    for(int i=0;i<maxNumberInList+1;i++)
        auxArray[i]=NULL;

    for(int i=0;i<sizeOfList;i++){
        Node* n = new Node(list[i],NULL);
        insertNode(n,auxArray,list[i]);
    }

    for(int i=0;i<maxNumberInList+1;i++){
        if(auxArray[i] == NULL)
            continue;
        else{
            //pop out elements in FIFO fashion
            do{
                cout<<auxArray[i]->key<<" ";
                auxArray[i] = auxArray[i]->next;
            }while(auxArray[i] != NULL);
        }
    }
}

int main(){
    int A[] = {5,7,6,1,3,9,4,8,2};
    int n = sizeof(A)/sizeof(A[0]);
    binBucketSort(A,n);
    
    return 0;
}