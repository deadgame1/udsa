#include <iostream>

using namespace std;


int array[9] = {1,2,3,4,5,6,7,9,10};
/**
 * @brief Finding single missing element in a sequence of natural numbers starting from 1.
 * using sum of n natural numbers.
 * eg - 1,2,3,4,5,6,7,9,10,11
 * missing element = 8
 * @return int 
 */
int findSingleMissing(){
    int arraySize = sizeof(array)/sizeof(array[0]);
    int sum = 0;
    for(int i=0; i<arraySize; i++){
        sum += array[i];
    }

    //sum of first n natural numbers
    int lastElemOFSeries = array[arraySize-1];
    
    int sumShouldBe = (lastElemOFSeries*(lastElemOFSeries+1))/2;
    
    int missingElem = sumShouldBe - sum;

    return missingElem;
}


int array2[9] = {4,5,6,7,8,9,11,12,13};
/**
 * @brief Finding single missing element in a sequence of natural numbers NOT necessarily starting from 1. 
 * using difference of element and its index.
 * eg - 4,5,6,7,8,9,11,12,13
 * missing element = 10
 * 
 * @return int 
 */
int findSingleMissingElement2(){
    int diff;
    diff = array2[0] - 0;
    int size = sizeof(array2)/sizeof(array2[0]);
    for(int i = 0; i<size; i++){
        if((array2[i]-i) != diff){
            return i+diff;
        }
    }

    return -1;
}

int C[8] = {6,7,8,9,12,13,14,16}; 
/**
 * @brief finding multiple missing elements in sequence of n natural numbers NOT necessarily starting from 1
 * series - {6,7,8,9,12,13,14,16}
 *           0,1,2,3,4 
 * 10,11 are missing consecutively, and then 15 is missing
 * 
 * @return void 
 */
void findMultipleMissingElements(){
    int diff = C[0] - 0;
    int arraySize = sizeof(C)/sizeof(C[0]);
    for(int i = 0; i<arraySize; i++){
        if((C[i]-i) != diff){
            while(diff < C[i]-i){
                cout<<diff+i<<endl;
                diff++;
            }
        }
    }
}

/**
 * @brief finding multiple missing elements in an unsorted array
 * using hash table.
 * 
 * Time taken - O(n)
 * 
 * @return 
 */
void findMultipleMissingInUnsortedList(){


    return;
}

int main(){
    findMultipleMissingElements();

    return 0;
}