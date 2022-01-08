#include <iostream>
#include <cmath>
#include <random>

using namespace std;

//Column major mapping
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
        void randomizeMatrixElements(); //inserts random elements in matrix
};

void LowerTriangular::display()
{
    for(int i=1;i<=dimension;i++){
        for(int j=1;j<=dimension;j++){
            if(i>=j) {
                cout<<A[dimension*(j-1)-((j-2)*(j-1)/2)+(i-j)]<<" ";
            }else {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}
void LowerTriangular::get(int i, int j)
{
    if(i>=j) {
        cout<<A[dimension*(j-1)-((j-2)*(j-1)/2)+(i-j)];
    }else {
        cout<<"0";
    }
}
void LowerTriangular::set(int i, int j, int x)
{
    if(i>=j) {
        A[dimension*(j-1)-((j-2)*(j-1)/2)+(i-j)] = x;
    }
}

void LowerTriangular::randomizeMatrixElements()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 10); // define the range
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
    LowerTriangular usersMatrix(dimensionInput);
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