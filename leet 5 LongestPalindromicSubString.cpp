//leet 5 longest palindromic substring



bool palPal(string x);

class Solution {
public:
    string longestPalindrome(string s) {
        //if odd length take the middle three to start
        //if it can grow and be pali then grow it both sides
        //if even take the middle two and grow it  same as for odd
        //if the pali is on either end then grow from the end

        int mid,start,subLen = 0;
        int length = s.size();
        if (length % 2 == 0 ){
            mid = length/2+1;
            start = mid-1;
            subLen = 3;
            
        }else
        {
            mid=length/2;
            start = mid;
            subLen = 2;
        }


//need an if here
        while (isPali (s.substr(start, subLen)) || start >0 || (start + subLen)<= length){
            --start;
            subLen+=2;
        }
        
    }
};

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