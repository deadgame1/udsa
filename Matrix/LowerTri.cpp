#include <iostream>
#include <cmath>

using namespace std;

//Row major mapping
class LowerTriangular{
    private:
        int dimension;
        int *A;
    public:
        LowerTriangular(){
            this->dimension = 2;
            A = new int[3];
        }
        LowerTriangular(int d){
            this->dimension = d;
            int totalNonZero = (pow(dimension,2)+dimension)/2;
            A = new int[totalNonZero]; //according to total number of elements.
        }
        ~LowerTriangular(){
            delete []A;
        }
        void display();
        void get(int i, int j);
        void set(int i, int j, int x);
};

void LowerTriangular::display(){
    for(int i=1;i<=dimension;i++){
        for(int j=1;j<=dimension;j++){
            if(i>=j) {
                cout<<A[(i*(i-1))/2 + j-1]<<" ";
            }else {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}
void LowerTriangular::get(int i, int j){
    if(i>=j) {
        cout<<A[(i*(i-1))/2 + j-1];
    }else {
        cout<<"0";
    }
}
void LowerTriangular::set(int i, int j, int x){
    if(i>=j) {
        A[(i*(i-1))/2 + j-1] = x;
    }
}

int main(){
    LowerTriangular d(4);
    d.set(1,1,1);
    d.set(2,1,2);
    d.set(2,2,4);
    d.set(3,1,6);
    d.set(3,2,8);
    d.set(3,3,3);
    d.set(4,1,5);
    d.set(4,2,7);
    d.set(4,3,9);
    d.set(4,4,4);
    d.display();

    return 0;
}