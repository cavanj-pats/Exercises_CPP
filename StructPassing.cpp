//
#include <iostream>
#include <stdio.h>


using namespace std;

struct rectangle {
    int length ;
    int breadth;
};

void initialize(struct rectangle &r, int l, int b){
    r.length = l;
    r.breadth = b;
}

int area (struct rectangle r){
    return r.length * r.breadth;
}

int main(){
    struct rectangle r1;
    int l=0, b=0;

    
    cout << "Enter length: " ;
    cin >> l ;
    cout <<"Enter breadth: " ;
    cin >> b ;
    cout << endl;

    initialize(r1, l, b);  //wont' work if pass by value.s

    printf ("Area= %d \n", area(r1));

    return 0;

}