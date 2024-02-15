//reverse a string
//stringReverse.c

#include "stdio.h"


int main()
{
    char s[] = "hello";
    int i;
    
    for (i = 0; s[i]!='\0'; i++)
    {}
    
    char r[i];   //i is the size of the array that we want r to be
    i = i - 1;   //index it to move to the left of '\0'
    int j = 0;
    for (j=0; i>=0; i--, j++)
    {
        r[j] = s[i];
    }
    r[j]='\0';

    printf("%s reversed is %s \n", s, r);

    return 0;

}