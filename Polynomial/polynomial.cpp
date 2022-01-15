#include <iostream>
#include <math.h>

using namespace std;

class Term{
    private:
        int coef;
        int exp;
    public:
        // dummy constructor required so that array of Term can be declared dynamically i.e in heap.
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
        void setCoef(int coef){
            this->coef = coef;
        }
        void setExp(int exp){
            this->exp = exp;
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
        }
        void initializeTerms(){
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
        void setNumberOfTerms(int no){
            this->n = no;
        }
        void display(){
            int i;
            for(i=0;i<n;i++){
                cout<<"Coef = "<<t[i].getCoef()<<" Exp = "<<t[i].getExp()<<endl;
            }
            cout<<endl;
        }
        int evaluateForX(int x){
            int result = 0;
            for(int i=0;i<n;i++){
                result = result + t[i].getCoef()*pow(x,t[i].getExp());
            }
            return result;
        }
        Polynomial* add(Polynomial p2){
            int i,j,k,sum;
            i=j=k=0;
            int totalSize = n + p2.n;
            Polynomial* p3;
            p3 = new Polynomial(totalSize);
            p3->t = new Term[totalSize];

            while(i < n && j < p2.n){
                sum=0;
                if(t[i].getExp() > p2.t[j].getExp()){
                    p3->t[k++] = t[i++];
                }else if(p2.t[j].getExp() > t[i].getExp()){
                    p3->t[k++] = p2.t[j++];
                }else{
                    sum = t[i].getCoef() + p2.t[j++].getCoef();
                    p3->t[k].setCoef(sum);
                    p3->t[k++].setExp(t[i++].getExp());
                }
            }

            for(;i<n;i++)
                p3->t[k++] = t[i];

            for(;j<p2.n;j++)
                p3->t[k++] = p2.t[j];

            p3->setNumberOfTerms(k);

            return p3;
        }
};

int main(){
    int n,coef,exp;
    cout<<"Enter no of terms for 1st poly"<<endl;
    cin>>n;
    Polynomial p1(n);
    p1.initializeTerms();
    p1.display();
    cout<<"Enter no of terms for 2nd poly"<<endl;
    cin>>n;
    Polynomial p2(n);
    p2.initializeTerms();
    p2.display();

    Polynomial* p3 = p1.add(p2);
    p3->display();
    cout<<endl;

    return 0;
}