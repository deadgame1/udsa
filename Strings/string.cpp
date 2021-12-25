#include <iostream>

using namespace std;

int stringlength(char *str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {

    }
    return i;
}

char * uppercase(char *str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i] >= 97 && str[i] <=122){
            str[i] = str[i] - 32;
        }
    }
    return str;
}

char * lowercase(char *str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i] >= 65 && str[i] <=90){
            str[i] = str[i] + 32;
        }
    }
    return str;
}

char * toggleCase(char *str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i] >= 65 && str[i] <=90){
            str[i] = str[i] + 32;
        }else if(str[i] >= 97 && str[i] <=122){
            str[i] = str[i] - 32;
        }
    }
    return str;
}

void reverseStringUsingAuxillaryString(char* str)
{
    int size = stringlength(str);
    char B[size+1];
    int i,j;
    for(i=size-1,j=0;i > -1;i--,j++)
    {
        B[j] = str[i]; 
    }
    B[j] = '\0'; //termination character.
    cout<<B<<endl;

    return;
}

void reverseString(char* str)
{
    int size = stringlength(str);
    int i,j;
    char temp;
    for(i=0,j=size-1;i < j;i++,j--)
    {
        char temp = str[i];
        str[i] = str[j]; 
        str[j] = temp;
    }
    cout<<str<<endl;

    return;
}

/**
 * @brief only numerical and alphabets are allowed
 * 
 */
int validatingString(char* str){
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(!(str[i] >= 65 && str[i]<=90) && !(str[i] >= 97 && str[i]<=122) && !(str[i] >= 48 && str[i]<=57)){
            return 0;
        }
    }
    return 1;
}

int countVowels(char* str){
    int i;
    int vcount=0;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
            || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
            vcount++;
        }
    }
    return vcount;
}

int countConsonants(char* str){
    int i;
    int ccount=0;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u'
            && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U'
            && ((str[i] >=65 && str[i]<=90) || (str[i] >=97 && str[i]<=122)) ){
            ccount++;
        }
    }
    return ccount;
}

int countWordsInAString(char* str){
    int wordCount = 1;
    for(int i=0;i<stringlength(str);i++)
    {
        if(str[i] == ' ' && str[i-1] != ' '){
            wordCount++;
        }
    }

    return wordCount;
}

/**
 * @brief O(n^2) operation.
 * 
 * @return void 
 */
void findingDuplicatesInAString(char* str){
    int i=0;
    int j=0;
    while(str[i]!='\0')
    {
        if(str[i] != -1){
            for(j=i+1;str[j]!='\0';j++){
                if(str[i] == str[j]){
                    cout<<str[i]<<" - is repeating"<<endl;
                    str[j] = -1;
                }
            }
        }
        
        i++;
    }

    return;
}

/**
 * @brief O(n) operation using hash table
 * 
 * @return void 
 */
void findingDuplicatesInALowerCaseStringUsingHashTable(char* str){
    int i,j;
    int hash[26] = {0};
    for(i=0;str[i]!='\0';i++)
    {
        hash[str[i]-97]++;
    }

    char c;
    for(j=0;j<26;j++){
        if(hash[j] > 1){
            c=j+97;
            cout<<c<<" - is repeating character"<<endl;
        }
    }

    return;
}

/**
 * @brief O(n) operation using hash table
 * works for mixed case (uppercase+lowercase)
 * 
 * uppercase 65-90
 * lowercase 97-122
 * number - 48-57
 * 
 * @return void 
 */
void findingDuplicatesInAStringUsingHashTable(char* str){
    int i,j;
    int sizeOfHashTable = 52;
    int hash[sizeOfHashTable] = {0};
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>=97 && str[i]<=122){
            hash[str[i]-97]++;
        }else{
            hash[str[i]-39]++;
        }
    }

    char c;
    for(j=0;j<sizeOfHashTable;j++){
        if(hash[j] > 1){
            if(j>=0 && j <=25){
                c=j+97;
                cout<<c<<" - is repeating character"<<endl;
            }else{
                c=j+39;
                cout<<c<<" - is repeating character"<<endl;
            }
            
        }
    }

    return;
}

/**
 * @brief using bitwise operations to find duplicate characters.
 * works for both cases
 * caveat - cannot return the count of duplicates right now.
 */
void findDuplicatesInAStringUsingBitwiseOperation(char* str)
{
    long int H = 0; //long bytes - 8 bytes
    
    int i;
    int x = 0;
    for(i=0;str[i]!='\0';i++)
    {
        x = 1;

        //left shift
        if(str[i]>=97 && str[i]<=122){
            x = x << (str[i]-97); 
        }else{
            x = x << (str[i]-39);
        }
        
        if((H & x) > 0){ //AND, Masking/checking if bit is already set
            printf("%c",str[i]);  
        }else{
            H = H | x; //OR, Merging, setting the bit
        }
    }

    return;
}

int main(){
    //char name[] = "Aditya";
    char name[] = "adItyaI";
    findDuplicatesInAStringUsingBitwiseOperation(name);

    // if(validatingString(name) == 1)
    // {
    //     cout<<"Valid"<<endl;
    // }else{
    //     cout<<"Invalid"<<endl;
    // }
    //cout<<validatingString(name)<<endl;
    
    return 0;
}