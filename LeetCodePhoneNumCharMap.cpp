//LeetCode - phone number character letter mapping.  return all letter combinations from an input of numbers.

#include <iostream>
#include <vector>
#include <string>


using namespace std;

/*
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int * inputDigits = new int[digits.length()-1];
        int currDigit =0;
        mapsize = 1;
        
        for(int i = 0; i<digits.length(); i++){       
            inputDigits[i] =  (int) (digits[i]-'0');  //i recall this but forgot.  need to subt
            mapsize *= map[inputDigits[i]].length();
        }
        
        for(int i=0; i<digits.length(); i++){
            //if there is no input digit can return
        
            for (int j=0; j<map[inputDigits[i]].length(); j++){
                //if the digit refers to a map with no characters can return here
                if (inputDigits[i]==0 || inputDigits[i]=1){
                    //exit
                }
                



            }
        }

        switch (digits.length()){
            case 0:
                return "";
            case 1:

            case 2:

            case 3:

            case 4:

            default:
                return ""
        }

        //while loop to traverse each inputDigits
        for (int j=0; j<mapsize; j++){
                //populate the vector
                record = "";
                letterCombinations.pushback(traverse(0, digits, &record));

            }


        

        delete [] inputDigits;
    }

private:    
    string map[10];
    int mapsize ;
    string record;


};

Solution::Solution(){
    map[0] = "0";
    map[1] = "1";
    map[2] = "abc";
    map[3] = "def";
    map[4] = "ghi";
    map[5] = "jkl";
    map[6] = "mno";
    map[7] = "pqrs";
    map[8] = "tuv";
    map[9] = "wxyz";
}

string oneDigit(int digit){
    string temp;
    temp.push_back(map[digit][0]);
    temp.push_back(",");
    temp.push_back(map[digit][1]);
    temp.push_back(",");
    temp.push_back(map[digit][2");
    temp.push_back(",");
    if(digit == 7 || digit ==8) temp.push_back(map[digit][3]);

    return temp;
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

push  character 1,  character 1, character 1 character 1
push  character 1, character 1 character 1, character 2
1 1 1 1
1 1 1 2
1 1 1 3
1 1 1 4
1 1 2 1
1 1 2 2
1 1 2 3
1 1 2 4
1 1 3 1 
1 1 3 2
1 1 3 3 
1 1 3 4
1 2 1 1
1 2 1 2         
...
//need to solve for up to four digits
string traverse(int inputDigit, string digits, string *record){
    if inputdigit < digits.length(){} 
        inputDigit++;
        traverse = ;
}




*/



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

   int mapsize = 1;  //this will be the size of the array that holds the solution
   //max is four digits.  max size could be 
   
  // Solution mySol;


   string strDigits = "6789";
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

    delete[] inputDigits;
    delete[] mergedMap;
        
    return 0;
}