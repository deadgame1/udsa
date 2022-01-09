#include <iostream>
#include <cmath>
#include <random>

using namespace std;

class NormalMatrix{
    private:
        int dimension;
        int **A;
    public:
        NormalMatrix(){
            this->dimension = 2;
            A = new int*[this->dimension]; //2=row count & col count also
            for(int i=0;i<this->dimension;i++){
                A[i] = new int[this->dimension];
            }
        }
        NormalMatrix(int d){
            this->dimension = d;
            A = new int*[this->dimension]; 
            for(int i=0;i<this->dimension;i++){
                A[i] = new int[this->dimension];
            }
        }
        ~NormalMatrix(){
            for(int i=0;i<this->dimension;i++){
                delete []A[i];
            }
            delete []A;
        }
        void display();
        int get(int i, int j);
        void set(int i, int j, int x);
        void randomizeMatrixElements(); //inserts random elements in matrix
        void transpose();
};

void NormalMatrix::display()
{
    for(int i=1;i<=dimension;i++){
        for(int j=1;j<=dimension;j++){
            cout<<get(i,j)<<" ";
        }
        cout<<endl;
    }
}
int NormalMatrix::get(int i, int j)
{
    return A[i-1][j-1];
}

void NormalMatrix::set(int i, int j, int x)
{
    A[i-1][j-1] = x;
}

void NormalMatrix::randomizeMatrixElements()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 9); // define the range
    int i, j;
    for(int i=1;i<=dimension;i++){
        for(int j=1;j<=dimension;j++){
            set(i,j,distr(gen));
        }
    }
}

void NormalMatrix::transpose(){
    int i, j, temp;
    for(int i=1;i<=dimension;i++){
        for(int j=1;j<=dimension;j++){
            if(i>=j) {
               temp = get(j,i);
               set(j,i,get(i,j)); 
               set(i,j,temp);
            }
        }
    }
}

int main(){
    int choice=0;
    int dimensionInput, row, column, elem;
    cout<<"Please enter dimension of the matrix - "<<endl;
    cin>>dimensionInput;
    NormalMatrix usersMatrix(dimensionInput);
    cout<<"Matrix created"<<endl;

    do
    {
        //display the menu
        cout<<"Menu:"<<endl;
        cout<<"1. Set"<<endl;
        cout<<"2. Get"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Randomize Elements"<<endl;
        cout<<"5. Transpose Matrix"<<endl;
        cout<<"6. Exit"<<endl;
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
        case 5: //transpose
            usersMatrix.transpose();
            break;
        default:

            break;
        }
    } while (choice >0 && choice <6);
    
    return 0;
}