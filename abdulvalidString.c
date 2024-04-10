//validString.c
//check to see if string meets a desired format....such as a password
//abdul only did uCase, lCase, and numbers and his if state had "not"
//!uCase && !lCase && !number then invalid so stop once you know its not valid.


#include "stdio.h"

int validString(char* s)
{
    int uCase = 0;
    int lCase = 0;
    int number = 0;
    int specialchar = 0;   //  !,  @,  #,  $,  %,  ^,  & 
                           // 33, 64, 35, 36, 37, 94, 38

    int i;
    for(i=0; s[i]!='\0'; i++)
    {
        if(s[i]>=65 && s[i] <=90 && uCase !=1){ 
            uCase=1;    //lower case
        } else if(s[i]>=97 && s[i]<= 122 && lCase !=1){
             lCase = 1;   //lower case
        } else if(s[i]>=48 && s[i]<= 57 && number!= 1) {
              number=1;   //number 
        } else if(s[i]==33 || s[i]== 64 || s[i]==35 || s[i]==36 
        || s[i]==37 || s[i]== 94 || s[i]==38) {
            specialchar=1;
        }

        if(specialchar+uCase+lCase+number == 4)
        {
            return 1;
        } 
    }
    return 0;
}



int main()
{
    char pswd[]="James!32";

    printf("Valid password:=%d\n\n", validString(pswd));

    return 0;
}