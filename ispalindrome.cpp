//ispalindrome.cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool palPal(string x);

bool isPalindrome(int x){
   // int length = 0;
    std::string str = std::to_string(x);
    return palPal(str);

   
}

bool palPal(string str){
    int length =0;
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
            if((str[0] != str[str.length()-1]) || (str[1] != str[str.length()-2])){
                return false;  //whenever this happens return false
            }
            else{
                length = str.length()-2;
               // if (isPalindrome( atoi( str.substr(1,length).c_str() ) ) )
               if(palPal(str.substr(1,length)))
                    return true;
                else 
                    return false;
                       
            }
            break;
    }
}

int main(){
    int x = 1000110001;

    if (isPalindrome(x) )
        cout << x << " is_palindrome" << endl;
    else
        cout << x << " is not palindrome"<< endl;

    return 0;

}
