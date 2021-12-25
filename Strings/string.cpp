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

int main(){
    //char name[] = "Adityarty";
    char name[] = "Hey how are you doing man ?";
    cout<<countWordsInAString(name)<<endl;
    // if(validatingString(name) == 1)
    // {
    //     cout<<"Valid"<<endl;
    // }else{
    //     cout<<"Invalid"<<endl;
    // }
    //cout<<validatingString(name)<<endl;
    
    return 0;
}