#include <iostream>
#define SIZE 10

using namespace std;

int hashing(int key){
    return key % SIZE;
}
int probe(int HT[], int key){
    int index = hashing(key);

    int i=0;
    while(HT[hashing(key+i)] != 0)
        i++;

    return hashing(key+i);
}
void insert(int HT[], int key){
    int index = hashing(key);
    if(HT[index] == 0){
        HT[index] = key;
    }else{
        index=probe(HT,key);
        HT[index]=key;
    }
}

int main(){
    int HT[SIZE]={0};

    insert(HT, 12);
    insert(HT, 22);
    insert(HT, 32);

    return 0;
}