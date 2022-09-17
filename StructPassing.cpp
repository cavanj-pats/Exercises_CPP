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

    initialize(r1, 4,5);  //wont' work if pass by value.s

    printf ("Area= %d \n", area(r1));

    return 0;

}