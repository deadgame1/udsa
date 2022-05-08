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

int countDigits(int number){
    if(number < 10)
        return 1;
    int i=1;
    int remainder;
    int carry = number;
    do{
        remainder = carry % 10;
        carry = carry / 10;
        i++;
    }while(carry > 9);

    return i;
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

void radixSort(int list[], int sizeOfList){
    int maxNumberInList = findMax(list,sizeOfList);
    int digitsOfMaxNumber = countDigits(maxNumberInList); //max digits = number of passes

    Node **auxArray = new Node*[10]; //radix Sort with bin size 10 [decimal]

    for(int i=0;i<10;i++)
        auxArray[i]=NULL;

    int divisor = 1;
    for(int i=0;i<digitsOfMaxNumber;i++){

        //insert in list
        for(int j=0;j<sizeOfList;j++){
            int curr = list[j];

            int significantDigit;
            if(countDigits(curr) < i){
                significantDigit = 0;
            }else{
                significantDigit = ( curr / divisor ) % 10;
            }

            //insert
            Node* n = new Node(curr,NULL);
            insertNode(n,auxArray,significantDigit);
        }

        //popout and make new list for next pass
        int x=0;
        for(int k=0;k<10;k++){
            if(auxArray[k] == NULL)
                continue;
            else{
                //pop out elements in FIFO fashion
                Node *y = auxArray[k];
                do{
                    list[x] = y->key;
                    x++;
                    y = y->next;
                }while(y != NULL);
                auxArray[k] = NULL; //empty the bin
            }
        }

        //increment divisor by 10
        divisor = divisor * 10;
    }

    for(int i=0;i<sizeOfList;i++){
        cout<<list[i]<<" ";
    }
}

int main(){
    int A[] = {50,7,69,100,30,9,4010,8,21};
    int n = sizeof(A)/sizeof(A[0]);
    radixSort(A,n);
    
    //cout<<countDigits(1010)<<endl;
    
    return 0;
}