//abdul Quiz 1

#include <stdio.h>


void foo(int n, int sum)
{
    int k = 0, j = 0;
    if (n == 0) return;

    k = n % 10;
    j = n/10;
    sum = sum + k;
    foo(j, sum);
    
    printf("%d ",k);

}

int f (int &x, int c) 
{

   c-=1;

if (c == 0) return 1; 

x = x + 1; 

return f(x,c) * x;

        }


int fun(int n)

       { 

int x=1, k; 

if (n==1) return x; 

for (k=1; k<n; ++k) 

    x=x+fun(k) * fun(n-k); 

    return x; 

        }



int main ()

{
int p = 5;

int res = f(p,p);

int a = 2048, sum = 0;

foo (a, sum);

printf("%d \n", sum);

printf("f(5,5) =%d\n", res);
printf("fun(5) = %d\n",fun(5));
return 0;

}