//class rectangle using scope resolution
//good practice

#include <iostream>

using namespace std;

class Rectangle{
    private:
        int length;
        int breadth;
    
    public:
    Rectangle();
    Rectangle(int l, int b);
    void initialize(int l, int b) { length = l, breadth=b;}
    int Area();
    ~Rectangle();
    
};

Rectangle:: Rectangle(){
    length = 0;
    breadth =0;
}

Rectangle:: Rectangle(int l, int b){
    length = l;
    breadth = b;
}

int Rectangle::Area(){
    return length * breadth;
}
Rectangle::~Rectangle(){} 



int main(){
    //Rectangle r1;
    int l=0, b=0;

    
    cout << "Enter length: " ;
    cin >> l ;
    cout <<"Enter breadth: " ;
    cin >> b ;
    cout << endl;

    Rectangle r1(l, b); 

    printf ("Area= %d \n", r1.Area());

    return 0;

}