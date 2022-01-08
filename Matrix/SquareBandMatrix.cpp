#include <iostream>
#include <cmath>
#include <random>

using namespace std;

//Square Band Matrix stored in a 1D array, 
//total 3 lower diagonals, 1 main diagonal, 3 upper diagonals
//first lower Diagonals, then main, then upper diagonals.
class SquareBandMatrix{
    private:
        int dimension;
        int *A;
    public:
        SquareBandMatrix(){
            this->dimension = 2;
            A = new int[3];
        }
        SquareBandMatrix(int d){
            this->dimension = d;
            int totalNonZero = 7*dimension - 12; // 2*(n-3 + n-2 + n-1) + n = 7n-12 
            A = new int[totalNonZero]; //according to total number of elements.
        }
        ~SquareBandMatrix(){
            delete []A;
        }
        void display();
        void get(int i, int j);
        void set(int i, int j, int x);
        void randomizeMatrixElements(); //inserts random elements in matrix
};

void SquareBandMatrix::display()
{
    for(int i=1;i<=dimension;i++){
        for(int j=1;j<=dimension;j++){
            get(i,j);
        }
        cout<<endl;
    }
}
void SquareBandMatrix::get(int i, int j)
{
    if(i-j==3) {
        cout<<A[i-4]<<" ";
    }else if(i-j==2){
        cout<<A[dimension-3+i-3]<<" ";
    }else if(i-j==1){
        cout<<A[2*dimension-5+i-2]<<" ";
    }else if(i-j==0){
        cout<<A[3*dimension-6+i-1]<<" ";
    }else if(i-j==-1) {
        cout<<A[4*dimension-6+i-1]<<" ";
    }else if(i-j==-2) {
        cout<<A[5*dimension-7+i-1]<<" ";
    }else if(i-j==-3) {
        cout<<A[6*dimension-9+i-1]<<" ";
    }else{
        cout<<"0 ";
    }
}
void SquareBandMatrix::set(int i, int j, int x)
{
    if(i-j==3) {
        A[i-4]=x;
    }else if(i-j==2){
        A[dimension-3+i-3]=x;
    }else if(i-j==1){
        A[2*dimension-5+i-2]=x;
    }else if(i-j==0){
        A[3*dimension-6+i-1]=x;
    }else if(i-j==-1) {
        A[4*dimension-6+i-1]=x;
    }else if(i-j==-2) {
        A[5*dimension-7+i-1]=x;
    }else if(i-j==-3) {
        A[6*dimension-9+i-1]=x;
    }
}

void SquareBandMatrix::randomizeMatrixElements()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 9); // define the range
    int i, j;
    for(int i=1;i<=dimension;i++){
        for(int j=1;j<=dimension;j++){
            if(i-j==3) {
                A[i-4]=distr(gen);
            }else if(i-j==2){
                A[dimension-3+i-3]=distr(gen);
            }else if(i-j==1){
                A[2*dimension-5+i-2]=distr(gen);
            }else if(i-j==0){
                A[3*dimension-6+i-1]=distr(gen);
            }else if(i-j==-1) {
                A[4*dimension-6+i-1]=distr(gen);
            }else if(i-j==-2) {
                A[5*dimension-7+i-1]=distr(gen);
            }else if(i-j==-3) {
                A[6*dimension-9+i-1]=distr(gen);
            }
        }
    }
}

int main(){
    int choice=0;
    int dimensionInput, row, column, elem;
    cout<<"Please enter dimension of the matrix - "<<endl;
    cin>>dimensionInput;
    SquareBandMatrix usersMatrix(dimensionInput);
    cout<<"Matrix created"<<endl;

    do
    {
        //display the menu
        cout<<"Menu:"<<endl;
        cout<<"1. Set"<<endl;
        cout<<"2. Get"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Randomize Elements"<<endl;
        cout<<"5. Exit"<<endl;
        cin>>choice;
        cout<<endl;

        switch (choice)
        {
        case 1: //set
            cout<<"Please enter row and column where element needs to be inserted - "<<endl;
            cin>>row;
            cin>>column;
            cout<<"Please enter the element to be inserted - "<<endl;
            cin>>elem;
            usersMatrix.set(row,column,elem);
            cout<<endl;
            break;
        case 2: //get
            cout<<"Please enter row and column to get the element at that index - "<<endl;
            cin>>row;
            cin>>column;
            usersMatrix.get(row,column);
            cout<<endl;
            break;
        case 3: //display
            usersMatrix.display();
            cout<<endl;
            break;
        case 4: //randomize
            usersMatrix.randomizeMatrixElements();
            break;
        default:

            break;
        }
    } while (choice >0 && choice <5);

    return 0;
}