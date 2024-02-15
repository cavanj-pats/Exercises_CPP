//length of string in c


#include "stdio.h"

int isValid(char *name)
{
    for(int i = 0; name[i]!='\0'; i++)
        {
            if(!(name[i]>=  65 && name[i]<= 90 ) || 
            !(name[i]>=97 && name[i]<= 122 ) ||
            !(name[i]>=48 && name[i]<=57 ))
                return 0;
        }

        return 1;
}
int main()
{
    char s[10];
    char a[] = "How are you?";

    //gets(s);  //gets reports warnings
    scanf("%s",s);  

    int i;
    int vcount = 0;
    int ccount = 0;
    char c;

    for (i = 0; s[i]!='\0'; i++)
    {

    }
    printf("\n%s length is =:%d\n",s,i);

    //reverse case
    for(i=0; s[i]!='\0';i++)
    {
        if(s[i]>='A' && s[i]<=90)
            s[i] = s[i]+32;
        else if (s[i]>=97 && s[i] <='z')
            s[i]=s[i]-32;

    }

    printf("\nCharcters Reversed: %s\n",s);

    //count vowels
    for(i=0; a[i]!='\0'; i++)
    {
        c=a[i];
        if(c=='a'|| c=='A'|| c =='e' || c=='E' || c == 'i' || c=='I'
         || c == 'o' || c=='O' || c == 'u' || c == 'U')
            {
                vcount++;
            }else if((c>=65 && c <=90)  || (c>= 97 && c <=122))
            {
                ccount++;
            }

    }
    printf("Vowel count in %s: %d\n",a , vcount);
    printf("Consonant count in %s: %d\n", a, ccount);

    //word count involves counting spaces then adding 1
    //count consecutive spaces as one space
    //valid numbers are 48-57
    
    printf("validity check of a: ");
    printf( isValid(a) ? "True" : "False");
    printf("\n");



    return 0;
}