//firstword.cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printAsc(int start, int end){
    if (start == end)
        cout << start << endl;
    if (start < end){
        cout << start << endl;
        printAsc(start+1, end);
        cout << start << endl; // tjs prints in reverse order unravelling the stack....
    }
}

int main(){
    printAsc(1,4);    
    

    return 0;

}
