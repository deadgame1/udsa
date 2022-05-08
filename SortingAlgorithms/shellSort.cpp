#include <iostream>

using namespace std;

void swapNum(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void shellSort(int list[], int sizeOfList){
    int gap,i;
    gap = sizeOfList / 2;
    if(gap <= 0)
        return;

    do{
        for(int i=0;i<sizeOfList;i++){
            int gapNext = list[i+gap];
            int curr = list[i];
            if(i+gap >= sizeOfList)
                continue;
            if(list[i] < list[i+gap])
                continue;
            else{
                swapNum(&list[i],&list[i+gap]);
                if(i-gap < 0)
                    continue;
                else{
                    int z = i-gap;
                    int *element = &list[i];
                    while(z >= 0){
                        if(*element < list[z]){
                            int debug = list[z];
                            swapNum(element,&list[z]);
                            element = &list[z];
                            z = z-gap;
                        }else
                            break;
                    }
                }
            }
        }
        gap = gap / 2;
    }while(gap > 0);
    
    for(int i=0;i<sizeOfList;i++)
        cout<<list[i]<<" ";
}

int main(){
    int A[] = {50,7,69,100,30,9,4010,8,21};
    int n = sizeof(A)/sizeof(A[0]);
    shellSort(A,n);

    return 0;
}