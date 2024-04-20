//abdulMatrix.c
//


#include "stdio.h"


//the first matrix will be a diagonal matrix. 
/*
3  0  0  0
0  4  0  0
0  0  1  0
0  0  0  9
*/

struct Matrix
{
    int A[10];
    int n;
};

/*
Since this is a diagonal matrix, only a one dimensional array is used to store the data.
Row == Col.   When using set,   Row 1 (and hence Col 1) refers to position 0 in the array.
note [i-1], when i == 1 it is array position 0.

I suppose when looking at arrays it is easier to start wtih Row 1 Col 1 as the upper left position
*/
void Set(struct Matrix *m, int i, int j, int x)
{
    //diagonal matrix
    if(i == j)
    {
        m->A[i-1] = x;     //could use A[((i-1)+(j-1)+m->n-1]  if not a diagonal matrix
    }
}

int Get(struct Matrix m, int i, int j)
{
    if(i == j)
        return m.A[i-1];  //since this is a diagonal matrix i == j
    else
        return 0;
}

void Display_Matrix(struct Matrix m)
{
    for(int i = 0; i<m.n; i++)
    {
        for(int j=0; j<m.n; j++)
        {    
            if(i == j) 
                printf("%d  ",m.A[i]);
            else
                printf("0  ");
        }

        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    m.n = 4;
    Set(&m,1,1,7), Set(&m,2,2,3), Set(&m, 3,3, 4), Set(&m, 4, 4, 8);

    Display_Matrix(m);


    return 0;
}