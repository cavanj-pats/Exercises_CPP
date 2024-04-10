//abdulfindDuplicatesInStringHash.c


#include "stdio.h"

//as an exercize add upper case coverage
void findDuplicatesInStringHash(char *s)
{
    //only lowercase letters are allowed for this function
    int H[26];
    for(int i=0; i<26; i++)
        H[i]=0;
    
    for(int i=0; s[i]!='\0'; i++)
        H[s[i]-97]++;   //adjust the counter up based on the ASCI value of the letter
    
    for(int i=0; i<26; i++)
    {
        if(H[i]>1)
        {
            printf("%c has duplicates.\n", i+97);
        }
    }      


}


int main()
{
    char name[]="hello";    //must be lower case

    findDuplicatesInStringHash(name);

    return 0;


}
