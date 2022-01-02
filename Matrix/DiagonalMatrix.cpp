#include <iostream>

using namespace std;

class Diagonal{
    private:
        int dimension;
        int *A;
    public:
        Diagonal(){
            this->dimension = 2;
            A = new int[dimension];
        }
        Diagonal(int d){
            this->dimension = d;
            A = new int[dimension];
        }
        ~Diagonal(){
            delete []A;
        }
        void display();
        void get(int i, int j);
        void set(int i, int j, int x);
};

void Diagonal::display(){
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            if(i==j) {
                cout<<A[i]<<" ";
            }else {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}
void Diagonal::get(int i, int j){
    if(i==j) {
        cout<<A[i-1];
    }else {
        cout<<"0";
    }
}
void Diagonal::set(int i, int j, int x){
    if(i==j) {
        A[i-1] = x;
    }
}

int main(){
    Diagonal d(5);
    d.set(1,1,1);
    d.set(2,2,2);
    d.set(3,3,3);
    d.set(4,4,4);
    d.set(5,5,5);
    d.display();

    return 0;
}