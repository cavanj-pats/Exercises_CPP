//Abdul Udemy Fibonacci

#include <stdio.h>

int Fib(int n)
{
    if (n<=1)
        return n;

    return Fib(n-2)+ Fib (n-1);  //excessive recursion is allowed here
}


int main()
{
    int x = 7;
    printf("Fibonacci number %d = %d\n",x, Fib(x));

    return 0;
}