//length of string in c


#include "stdio.h"


int main()
{
    char s[10];
    //gets(s);  //gets reports warnings
    scanf("%s",s);  

    int i;
    for (i = 0; s[i]!='\0'; i++)
    {

    }
    printf("\n%s length is =:%d\n",s,i);

    return 0;
}