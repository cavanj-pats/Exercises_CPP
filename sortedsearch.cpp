//sortedsearch.cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int sortedSearch(int srtArr[], int srtArrSize, int val){
    int low, high, mid;
    int ind;
    bool found = false;
    low = 0;
    high = srtArrSize;
    while (( found == false) && (low<=high) ){
        mid = (low + high)/2;
        if (srtArr[mid] == val){
            ind = mid;
            found = true;
        }
        else if (val < srtArr[mid])
            high = mid -1;
        else //val > srtArr[mid]
            low = mid + 1;

    }
    if (found == true)
        return ind;
    else
        return -1;
        

}


bool is_palindrome(int test){
    int length = 0;
    std::string str = std::to_string(test);
      
    switch (str.length()){
        case 1:
            return true;
            break;  //just to have it
        case 2: case 3:
            if(str[0] == str[str.length()-1])
                return true;
            else 
                return false;
    
                break;
            
        default:
            if(str[0] != str[str.length()-1]){
                return false;  //whenever this happens return false
            }
            else{
                length = str.length()-2;
                if (is_palindrome( atoi( str.substr(1,length).c_str() ) ) )
                    return true;
                else 
                    return false;
                       
            }
            break;
    }
}

/*
int main(){
    int x = 123221;

    if (is_palindrome(x) )
        cout << x << " is_palindrome" << endl;
    else
        cout << x << " is not palindrome"<< endl;

    
       

    return 0;

}
*/