//Compare Two Strings
//stringCompare.c


#include "stdio.h"


int main()
{
    char a[] = "apple";
    char b[] = "applc";
    int i;
    int j;
    for (i=0, j=0;a[i]!='\0' && b[j]!='\0'; i++, j++)
    {
        if(a[i] < b[j])
        {
            printf("a is less than b.\n");
            return -1;
        } else if(a[i] > b[j]) 
        {
            printf("a is greater than b.\n");
            return 1;
        }
    }
    printf("they are equal.\n");
    return 0;
}