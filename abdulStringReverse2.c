//abdulStringReverse2.c
//reverse a string without a second character array.

#include "stdio.h"


void reverseString(char *s)
{
    char t;
    int i;
    for(i=0; s[i]!='\0'; i++){

    }
    i = i-1;  
    for(int j=0; j<i; j++, i--){
        t = s[i];
        s[i]= s[j];
        s[j]=t;
    }
}


int main()
{
    char s[] = "Hello";
    printf("%s before reversing.\n",s);
    reverseString(s);
    printf("%s reversed\n", s);

    return 0;
}