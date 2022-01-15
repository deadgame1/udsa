#include <iostream>
#include <math.h>

using namespace std;

class Term{
    private:
        int coef;
        int exp;
    public:
        // dummy constructor
        Term() {}
        Term(int coef, int exp){
            this->coef = coef;
            this->exp = exp;
        }
        int getCoef(){
            return this->coef;
        }
        int getExp(){
            return this->exp;
        }
};
class Polynomial{
    private:
        int n;
        Term* t;
    public:
        // dummy constructor
        Polynomial() {}
        Polynomial(int n){
            this->n = n;
            int coef, exp;
            t = new Term[n];
            cout<<"Enter each term"<<endl;
            for(int i=0;i<n;i++){
                cout<<"entering term no. "<<i+1<<endl;
                cin>>coef;
                cin>>exp;
                t[i] = Term(coef,exp);
            }
        }
        void display(){
            int i;
            for(i=0;i<n;i++){
                cout<<"Coef = "<<t[i].getCoef()<<" Exp = "<<t[i].getExp()<<endl;
            }
        }
        int evaluateForX(int x){
            int result = 0;
            for(int i=0;i<n;i++){
                result = result + t[i].getCoef()*pow(x,t[i].getExp());
            }
            return result;
        }
};

int main(){
    int n,coef,exp;
    cout<<"Enter no of terms"<<endl;
    cin>>n;
    Polynomial p1(n);
    p1.display();
    cout<<endl;
    cout<<p1.evaluateForX(2);
    cout<<endl;

    return 0;
}