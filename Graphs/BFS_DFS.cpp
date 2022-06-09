#include <iostream>

using namespace std;
/**
 * represent a graph first using adjacency matrix or list
 * then do BFS, DFS
 * 
 *  
 */
class Node{
    public:
        int value;
        Node *next;
        Node(int val, Node* next = NULL){
            this->value = val;
            this->next = next;
        };
};

class Queue{
    public:
        Node *first = NULL;
        Node *rear = NULL;
        bool isEmpty(){
            if(first == NULL)
                return true;
            else    
                return false;
        };
        void enqueue(int element){
            Node *insertNode = new Node(element);
            if(first == NULL){
                first = rear = insertNode;
            }else{
                rear->next = insertNode;
                rear = insertNode;
            }
        };
        int dequeue(){
            if(isEmpty())
                return -1;
            else{
                int x = first->value;
                Node *p = first;
                if(first->next == NULL){
                    first=rear=NULL;
                }else{
                    first = first->next;
                }
                delete p;

                return x;
            }
        };
};

void BFS(int matrix[][7], int start, int n){
    int i = start;
    int j;
    Queue *q = new Queue();
    int visited[n] = {0};

    cout<<i<<" ";
    visited[i] = 1;
    q->enqueue(i);

    while(!q->isEmpty()){
        i = q->dequeue();
        for(j=1;j<n;j++){
            if(matrix[i][j] == 1 && visited[j] != 1){
                cout<<j<<" ";
                visited[j] = 1;
                q->enqueue(j);
            }   
        }
    }

    delete q;
}

void DFS(int matrix[][7],int start, int n){
    static int *visited = new int[n];
    if(visited[start] == 0){
        cout<<start<<" ";
        visited[start] = 1;
        for(int j=1;j<n;j++){
            if(matrix[start][j] == 1 && visited[j] != 1)
                DFS(matrix,j,n);
        }
    }    
}

/**
 * @brief 
 * 
 * @return int 
 */
int main(){
    int AM[7][7] = {{0,0,0,0,0,0,0},
                    {0,0,1,1,0,0,0},
                    {0,1,0,0,1,0,0},
                    {0,1,0,0,1,0,0},
                    {0,0,1,1,0,1,1},
                    {0,0,0,0,1,0,0},
                    {0,0,0,0,1,0,0}};
    DFS(AM,4,7);

    return 0;
}