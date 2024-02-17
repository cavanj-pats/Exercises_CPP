//
//
#include <iostream>

using namespace std;

class Arithmetic{
    private:
        int a;
        int b;
    public:
        Arithmetic(int a, int b);
        int add();
        int sub();
        
};

Arithmetic::Arithmetic(int a, int b){
    this->a = a;
    this->b = b;
}

int Arithmetic::add(){
    int c;
    c = a+b;
    return c;
}

int Arithmetic::sub(){
    int c;
    c = a-b;
    return c;
}



int main(){
    Arithmetic ar(9,7);

    cout << "Add: " << ar.add() << endl;
    cout << "Sub: " << ar.sub() << endl;


    return 0;

}