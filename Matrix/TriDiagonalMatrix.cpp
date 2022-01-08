#include <iostream>
#include <cmath>
#include <random>

using namespace std;

//elements stored in a 1D array, first lower Diagonal, then main, then upper diagonal.
class TriDiagonal{
    private:
        int dimension;
        int *A;
    public:
        TriDiagonal(){
            this->dimension = 2;
            A = new int[3];
        }
        TriDiagonal(int d){
            this->dimension = d;
            int totalNonZero = (pow(dimension,2)+dimension)/2;
            A = new int[totalNonZero]; //according to total number of elements.
        }
        ~TriDiagonal(){
            delete []A;
        }
        void display();
        void get(int i, int j);
        void set(int i, int j, int x);
        void randomizeMatrixElements(); //inserts random elements in matrix
};

void TriDiagonal::display()
{
    for(int i=1;i<=dimension;i++){
        for(int j=1;j<=dimension;j++){
            get(i,j);
        }
        cout<<endl;
    }
}
void TriDiagonal::get(int i, int j)
{
    if(i-j==1) {
        cout<<A[i-2]<<" ";
    }else if(i-j==0){
        cout<<A[dimension-1+i-1]<<" ";
    }else if(i-j==-1) {
        cout<<A[2*dimension-1+i-1]<<" ";
    }else{
        cout<<"0 ";
    }
}
void TriDiagonal::set(int i, int j, int x)
{
    if(i-j==1) {
        A[i-2]=x;
    }else if(i-j==0){
        A[dimension-1+i-1]=x;
    }else if(i-j==-1) {
        A[2*dimension-1+i-1]=x;
    }
}

void TriDiagonal::randomizeMatrixElements()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 9); // define the range
    int i, j;
    for(int i=1;i<=dimension;i++){
        for(int j=1;j<=dimension;j++){
            if(i-j==1) {
                A[i-2]=distr(gen);
            }else if(i-j==0){
                A[dimension-1+i-1]=distr(gen);
            }else if(i-j==-1) {
                A[2*dimension-1+i-1]=distr(gen);
            }
        }
    }
}

int main(){
    int choice=0;
    int dimensionInput, row, column, elem;
    cout<<"Please enter dimension of the matrix - "<<endl;
    cin>>dimensionInput;
    TriDiagonal usersMatrix(dimensionInput);
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
    
    // d.set(1,1,1);
    // d.set(2,1,2);
    // d.set(2,2,4);
    // d.set(3,1,6);
    // d.set(3,2,8);
    // d.set(3,3,3);
    // d.set(4,1,5);
    // d.set(4,2,7);
    // d.set(4,3,9);
    // d.set(4,4,4);
    // d.display();

    return 0;
}