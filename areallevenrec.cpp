//firstword.cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool areAllEven(int arr[], int num){
    bool res;
    if (num == 1){
        return (arr[0]%2==0);
    }
    else{
        res = areAllEven(arr,num-1);
        if (res == true){
            return (arr[num]%2==0);
        }
        else{
            return false;
        }
    }
}

int main(){
    int arr[4]={2, 4, 6, 9};
    if(areAllEven(arr,4))
        cout << "All are even"<< endl;
    else    
        cout << "Not all are even"<< endl;

    
       

    return 0;

}
