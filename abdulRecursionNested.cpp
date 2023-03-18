//nested recursion abdul
//abdulRecursionNested.cpp
//3/18/2023

#include "stdio.h"

int fun(int n)
{
    if (n > 100)
    {
        return n-10;
    }
    else
    {
        return fun(fun(n+11));
    }
}

int main()
{
    printf("%d ", fun(111));


    return 0;
}