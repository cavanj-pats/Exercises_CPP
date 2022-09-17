//
#include <iostream>
#include <stdio.h>


using namespace std;

class Rectangle {
  private:  
    int length ;
    int breadth;

public:
Rectangle( int l, int b){
    length = l;
    breadth = b;
}

int area (){
    return length * breadth;
}

};

int main(){
    //Rectangle r1;
    int l=0, b=0;

    
    cout << "Enter length: " ;
    cin >> l ;
    cout <<"Enter breadth: " ;
    cin >> b ;
    cout << endl;

    Rectangle r1(l, b); 

    printf ("Area= %d \n", r1.area());

    return 0;

}