#include <iostream>

using namespace std;

//so if you pass s2 by value to add function
//since Sparse matrix doesnt have a copy constructor explicitly defined, copy constructor is implicitly defined by the compiler.
// so the value inside the Element * ele is not copied properly
//and when add function ends, it deletes the formal parameter, and since the Element *ele was not properly copied the original ele gets
//deleted,i.e the actual paramters s2's ele gets deleted
//which means when s2 deconstructor is called, then it tries to free the memory used by s2 ele which is already gone so it throws
//this error - free() double error
// basically your class violates the rule of 3 - https://en.cppreference.com/w/cpp/language/rule_of_three
//
//explanation of error in the following links- 
//https://www.sololearn.com/Discuss/2389531/what-is-the-issue-when-this-message-come-out
//https://stackoverflow.com/questions/34943914/c-double-free-error-from-function-copy
//https://pencilprogrammer.com/cpp-tutorials/call-by-value-reference-address/
//https://stackoverflow.com/questions/30661806/double-free-or-corruption-when-deleting-reference
class Element{
    public:
        int i;
        int j;
        int x;
};
class Sparse{   
    private: 
        int n;
        int m;
        Element * ele;
        int num;
    public:
        Sparse(int n, int m, int num)
        {
            this->n = n;
            this->m = m;
            this->num = num;
            ele = new Element[num];
        }
        ~Sparse()
        {
            delete [] ele;
        }
        void read()
        {
            cout<<"Enter non zero elements"<<endl;
            for(int i=0;i<num;i++)
            {
                cin>>ele[i].i>>ele[i].j>>ele[i].x;
            }
        }
        void display(){
            int i,j,k;
            k=0;
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    if(i==ele[k].i && j==ele[k].j){
                        cout<<ele[k++].x<<" ";
                    }else{
                        cout<<"0 ";
                    }
                }
                cout<<endl;
            }
        }
        Sparse * add(Sparse &s2){
            if(n != s2.n || m != s2.m){
                cout<<"Matrix cannot be added"<<endl;
                return 0;
            }
            int i,j,k;
            i=j=k=0;
            Sparse * s3 = new Sparse(n,m,s2.num+num);
            while(i<num && j<s2.num){
                if(ele[i].i < s2.ele[j].i){
                    s3->ele[k++] = ele[i++];
                }else if(ele[i].i > s2.ele[j].i){
                    s3->ele[k++] = s2.ele[j++];
                }else{
                    if(ele[i].j < s2.ele[j].j)
                    {
                        s3->ele[k++] = ele[i++];
                    }else if(ele[i].j > s2.ele[j].j)
                    {
                        s3->ele[k++] = s2.ele[j++];
                    }else{
                        s3->ele[k] = ele[i];
                        s3->ele[k++].x = ele[i++].x + s2.ele[j++].x;
                    }
                }
            }

            for(;i<num;i++)
                s3->ele[k++] = ele[i];
            for(;j<s2.num;j++)
                s3->ele[k++] = s2.ele[j];

            s3->num = k;

            return s3;
        }
};

int main(){
    int n,m,num;
    Sparse * s3;
    cout<<"Enter dimension"<<endl;
    cin>>n>>m;
    cout<<"Enter no. of non zero"<<endl;
    cin>>num;
    Sparse s1(n,m,num);
    s1.read();

    cout<<"Enter dimension of 2nd matrix"<<endl;
    cin>>n>>m;
    cout<<"Enter no. of non zero in 2nd matrix"<<endl;
    cin>>num;
    Sparse s2(n,m,num);
    s2.read();

    s1.display();
    cout<<endl;
    s2.display();
    cout<<endl;
    s3 = s1.add(s2);
    s3->display();

    cout<<endl;
    return 0;
}