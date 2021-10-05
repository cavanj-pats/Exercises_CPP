//LeetCode - phone number character letter mapping.  return all letter combinations from an input of numbers.

#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int * inputDigits = new int[digits.length()-1];
        mapsize = 1;
        
        for(int i = 0; i<digits.length(); i++){       
            inputDigits[i] =  (int) (digits[i]-'0');  //i recall this but forgot.  need to subt
            mapsize *= map[inputDigits[i]].length();
        }
        
        //while loop to traverse each inputDigits
        do {
            for (int j=0; j<mapsize; j++){
                //populate the vector

            }


        }

        delete [] inputDigits;
    }

private:    
    string map[10];
    int mapsize ;

};

Solution::Solution(){
    map[0] = "";
    map[1] = "";
    map[2] = "abc";
    map[3] = "def";
    map[4] = "ghi";
    map[5] = "jkl";
    map[6] = "mno";
    map[7] = "pqrs";
    map[8] = "tuv";
    map[9] = "wxyz";
}

void merge(string &map, &inputDigits int num){
    //try 
    //if num is 0 then return empty map
    //if num is 1 then return a map of the inputDigits
    //if num > 1 then merge
    if (num == 0 ) return ;
    if (num ==1 )
        return ;
    for(int i=0;i<num;i++){


    }
        
}


int main(){ 
   string map[10];
    map[0] = "";
    map[1] = "";
    map[2] = "abc";
    map[3] = "def";
    map[4] = "ghi";
    map[5] = "jkl";
    map[6] = "mno";
    map[7] = "pqrs";
    map[8] = "tuv";
    map[9] = "wxyz";

   int mapsize = 1;
   
   Solution mySol;


   string strDigits = "78";
   int * inputDigits = new int[strDigits.length()-1];
   
   if(strDigits.length() ==0) mapsize =0;

   for(int i = 0; i<strDigits.length(); i++){       
       // cout << strDigits[i] << endl;
        inputDigits[i] =  (int) (strDigits[i]-'0');  //i recall this but forgot.  need to subtract as shown.
        //cout << inputDigits[i] << endl;
        mapsize *= map[inputDigits[i]].length();
    }
    cout << mapsize << endl;

    string * mergedMap = new string[mapsize];


    //cout << ( map[3])[2] <<"\t" << (map[3])[3]<< endl;

    for(int i=0; i<strDigits.length();i++)
        cout << map[inputDigits[i]] << endl;



    delete[] inputDigits;
    delete[] mergedMap;
        
    return 0;
}