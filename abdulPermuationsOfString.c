//abdulPermutationsOfString.c


#include "stdio.h"

void cswap(char*, int , int );


void perm(char *s, int k)
{
    static int A[10]={0};
    static char res[10];
    int i;

    if(s[k]=='\0')
    {
        res[k] = '\0';
        printf("%s\n", res);

    }
    else{
        for(i = 0; s[i]!='\0'; i++)
        {
            if (A[i]==0)    //if it is zero then it has not been added to the res solution
            {
                res[k] = s[i];     //add the character to res
                A[i]=1;            //set the A flag
                perm(s, k+1);      //call to check for another permutation
                A[i]=0;             //if perm returns then all items were found so turn off flags
            }
        }
    }

}

void permS(char *s, int l, int h)
{
   int i;

   if (l==h)
    {
        printf("%s\n",s);

    }
    else{
        for(i=l; i<=h;i++)
        {
            cswap(s, l, i);
            permS(s, l+1, h);
            cswap(s, l, i);

        }
    }
}

void cswap(char *s, int i, int l)
{
    char temp = s[i];
    s[i]=s[l];
    s[l]=temp;

}

int main()
{
    char s[]={'A', 'B', 'C'};

    //perm(s,0);
    //printf("\n");
    permS(s,0,2 );

    return 0;
}