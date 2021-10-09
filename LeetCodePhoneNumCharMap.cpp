//LeetCode - phone number character letter mapping.  return all letter combinations from an input of numbers.

#include <iostream>
#include <vector>
#include <string>


using namespace std;

string mp[10];

void build(int pos, int &length_error, string str, vector<string> &ans, string &D) ;  


class Solution {
public:
    vector<string> letterCombinations(string digits) {
       // int * inputDigits = new int[digits.length()-1];
       // int currDigit =0;
       
       
        mp[0] = "0"; mp[1] = "1"; mp[2] = "abc"; mp[3] = "def"; mp[4] = "ghi";
        mp[5] = "jkl"; mp[6] = "mno"; mp[7] = "pqrs"; mp[8] = "tuv"; mp[9] = "wxyz";
        
        vector<string> ans;
        int len = digits.size();
        if (!len) return ans;
       
        build(0, len, "", ans, digits);
        return ans;
         
    }  


};


void build(int pos, int &len, string str,  vector<string> &ans, string &D){
    //try 
    //pos is the position wihtin the input character sequence
    // L is the length of the character sequence
      // dig is the input character sequence
      //str is the buildup of the combined phone number characters culiminating in the answer
      int asciiValue = '0';
      int dpos = D[pos];  //to cast char to integer

    if(pos == len) ans.push_back(str) ;
    else{
        string letters = mp[dpos-asciiValue];
        for(int i=0;i<letters.size();i++){
            build(pos+1,len ,str+letters[i], ans, D);
        }

    }
        
}










int main(){ 
  
   
   int mapsize = 1;  //this will be the size of the array that holds the solution
   //max is four digits.  max size could be 
   
   Solution mySol;


   string strDigits = "45";
   int asciiValue = '0';
  vector<string> solution =  mySol.letterCombinations(strDigits);

   int * inputDigits = new int[strDigits.length()-1];
   
   if(strDigits.length() ==0) mapsize =0;

   for(int i = 0; i<strDigits.length(); i++){       
       // cout << strDigits[i] << endl;
        inputDigits[i] =  (int) (strDigits[i]-asciiValue);  //i recall this but forgot.  need to subtract as shown.
        //cout << inputDigits[i] << endl;
       // mapsize *= map[inputDigits[i]].length();
    }
    cout << mapsize << endl;

    string * mergedmap = new string[mapsize];
     
     /*
        for(int i = 0; i<digits.length(); i++){       
            inputDigits[i] =  (int) (digits[i]-'0');  //i recall this but forgot.  need to subt
           // mapsize *= map[inputDigits[i]].length();
        }
        
         */   

    //cout << ( map[3])[2] <<"\t" << (map[3])[3]<< endl;

/*
    for(int i=0; i<strDigits.length();i++){
        cout << map[inputDigits[i]] <<"\t"<<map[inputDigits[i]].length() << endl;
        cout << map[inputDigits[i]][1] << endl;
    }

     string temp;
     temp.push_back('"');
    temp.push_back(map[7][0]);
    temp.push_back(map[8][0]);
    temp.push_back('"');
    temp.push_back(',');
    temp.push_back('"');
    temp.push_back(map[7][1]);
    temp.push_back('"');
    temp.push_back(',');
    temp.push_back('"');
    temp.push_back(map[7][2]);
    temp.push_back('"');
    temp.push_back(',');
    temp.push_back('"');
    temp.push_back(map[7][3]);
    temp.push_back('"');
    cout << temp << endl;
  */

    for(int i=0; i<solution.size(); i++)
        cout << solution[i] << "\t"; 
       
     cout << endl;

    delete[] inputDigits;
    delete[] mergedmap;
        
    return 0;
}