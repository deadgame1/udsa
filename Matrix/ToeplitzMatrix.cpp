#include <iostream>
#include <cmath>
#include <random>

using namespace std;

//Row major mapping
class ToeplitzMatrix{
    private:
        int dimension;
        int *A;
    public:
        ToeplitzMatrix(){
            this->dimension = 2;
            A = new int[3];
        }
        ToeplitzMatrix(int d){
            this->dimension = d;
            int spaceRequired = 2*dimension - 1;
            A = new int[spaceRequired]; //according to total number of elements.
        }
        ~ToeplitzMatrix(){
            delete []A;
        }
        void display();
        void get(int i, int j);
        void set(int i, int j, int x);
        void randomizeMatrixElements(); //inserts random elements in matrix
};

void ToeplitzMatrix::display()
{
    for(int i=1;i<=dimension;i++){
        for(int j=1;j<=dimension;j++){
            get(i,j);
        }
        cout<<endl;
    }
}
void ToeplitzMatrix::get(int i, int j)
{
    if(i<=j) { 
        cout<<A[j-i]<<" ";
    }else {
        cout<<A[dimension+i-j-1]<<" ";
    }
}
void ToeplitzMatrix::set(int i, int j, int x)
{
    if(i<=j) { 
        A[j-i]=x;
    }else {
        A[dimension+i-j-1]=x;
    }
}

void ToeplitzMatrix::randomizeMatrixElements()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 9); // define the range
    int i, j;
    for(int i=1;i<=dimension;i++){
        for(int j=1;j<=dimension;j++){
            if(i<=j) { 
                A[j-i] = distr(gen);
            }else {
                A[dimension+i-j-1] = distr(gen);
            }
        }
    }
}

int main(){
    int choice=0;
    int dimensionInput, row, column, elem;
    cout<<"Please enter dimension of the matrix - "<<endl;
    cin>>dimensionInput;
    ToeplitzMatrix usersMatrix(dimensionInput);
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