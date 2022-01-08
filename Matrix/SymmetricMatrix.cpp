#include <iostream>
#include <cmath>
#include <random>

using namespace std;

//Symmetric Matrix implemented using Lower Triangular
class SymmetricMatrix{
    private:
        int dimension;
        int *A;
    public:
        SymmetricMatrix(){
            this->dimension = 2;
            A = new int[3];
        }
        SymmetricMatrix(int d){
            this->dimension = d;
            int totalNonZero = (pow(dimension,2)+dimension)/2;
            A = new int[totalNonZero]; //according to total number of elements.
        }
        ~SymmetricMatrix(){
            delete []A;
        }
        void display();
        void get(int i, int j);
        void set(int i, int j, int x);
        void randomizeMatrixElements(); //inserts random elements in matrix
};

void SymmetricMatrix::display()
{
    for(int i=1;i<=dimension;i++){
        for(int j=1;j<=dimension;j++){
            get(i,j);
            cout<<" ";
        }
        cout<<endl;
    }
}
void SymmetricMatrix::get(int i, int j)
{
    if(i>=j) {
        cout<<A[(i*(i-1))/2 + j-1];
    }else {
        cout<<A[(j*(j-1))/2 + i-1]; //swap i and j in formula
    }
}
void SymmetricMatrix::set(int i, int j, int x)
{
    if(i>=j) {
        A[(i*(i-1))/2 + j-1] = x;
    }else{
        A[(j*(j-1))/2 + i-1] = x; //swap i and j in formula
    }
}

void SymmetricMatrix::randomizeMatrixElements()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 9); // define the range
    int i, j;
    for(int i=1;i<=dimension;i++){
        for(int j=1;j<=dimension;j++){
            if(i>=j) {
                set(i,j,distr(gen));
            }
        }
    }
}

int main(){
    int choice=0;
    int dimensionInput, row, column, elem;
    cout<<"Please enter dimension of the matrix - "<<endl;
    cin>>dimensionInput;
    SymmetricMatrix usersMatrix(dimensionInput);
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