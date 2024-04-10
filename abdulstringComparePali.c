//abdul 137. Compare strings and Palindrome check
//abdulstringCompPali.c


#include "stdio.h"

int strCompareCaseSensitive(char *A, char * B)
{
    //compare two strings return 1 if equal 0 if not equal
    //can decide to make it case sensitive or not
    int i=0;
    int j=0;
    while(A[i]!='\0' || B[j]!='\0')
    {
        if(A[i]!=B[j])
        {
            return 0;
        }
        else
        {
            i++;
            j++;
        }
    }

    return 1;
}

int isPalindrome(char *s){
    //return 1 if palindrome (same backwards and forwards) and 0 if not
    int i;
    for(i=0; s[i]!='\0'; i++)
    {

    }
    i=i-1;
    for(int j=0; j<i; j++,i--)
    {
        if(s[j]!=s[i])
        {
            return 0;
            break;
        }
    }
    return 1;

}



int main()
{
    char A[]="poop";
    char B[]="James";

    if(strCompareCaseSensitive(A,B))
        printf("%s = %s\n",A,B);
    else
        printf("%s != %s\n",A, B);

    printf("%s is Palindrome? := %d\n",A,isPalindrome(A));

    
    return 0;
}