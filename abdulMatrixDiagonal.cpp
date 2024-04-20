//abdulMatrixDiagonal.cpp

#include <iostream>

using namespace std;

class Diagonal
{
    private:
        int *A;
        int n;
    public:
        Diagonal()
        {
            n=2;
            A=new int[2];
        }
        Diagonal(int n)
        {
            this->n=n;
            A=new int[n];
        }
        ~Diagonal()
        {
             delete []A;
        }
       
        void Set(int i,int j,int x);
        int Get(int i,int j);
        void Display();
        int GetDimension(){return n;}
};

void Diagonal::Set(int i, int j, int x)
{
    if(i == j)
    {
        this->A[i-1]= x;
    }
}

int Diagonal::Get(int i, int j)
{
    if(i == j)
    {
        return A[i-1];
    }

    return 0;
}

void Diagonal::Display()
{
    for(int i = 1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {    
            if(i == j) 
                cout << A[i-1] << "  ";
            else
                cout << "0  ";
        }

        cout<<endl;
    }
}



int main()
{
    Diagonal m(4);
    m.Set(1, 1, 3), m.Set(2, 2, 9), m.Set(3, 3, 5); m.Set(4, 4, 1);

    m.Display();




    return 0;
}