//Abdul tower of Hanoi
//abdul TowerOfHanoi.cpp   3/18/2023


#include <stdio.h>

//From A to C using B
void TOH (int n, int A, int B, int C)
{
    if (n>0)
    {
        TOH(n-1, A, C, B);  //from A to B using C
        printf("From %d to %d\n",A,C);
        TOH(n-1, B, A, C);   //from B to C using A
    }
}


int main()
{
    int n = 1;
    TOH(n,1,2,3);


    return 0;
}

