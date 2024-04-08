//stringWordCount.c
//4/8/2024


#include "stdio.h"

int stringWordCount(char* s)
{
    //if first character is a space, ignore it
    //count consecutive spaces "whitespace" as 1
    //don't count traililng spaces
    //Ascii code 32 is a space
    int wordcount=0;
    int wordStart = 0;   //use to flag start of a word
    int i;

    for(i=0; s[i]!='\0'; i++)
    {
        if(s[i]!= 32 && wordStart == 0) wordStart = 1;
        
        if(s[i]==32 && wordStart ==1){
            wordcount++;
            wordStart = 0 ;//toggle flag
        }
    }
    if(s[i]=='\0' && wordStart ==1) wordcount++;

    return wordcount;
}



int main()
{
    char s[] = "  Hello   my name is Jim  ";
    printf("%s has %d words.\n", s, stringWordCount(s));

    return 0;
}
