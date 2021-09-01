//firstword.cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int factorial(int num){
    if (num==1 || num == 0)
        return 1;
    if (num>1){
        return num * factorial(num-1);
        
    }
}

int main(){
    cout << "5! =" << factorial(5) << endl;    
    

    return 0;

}
