//abdulLowerTriangleMatrix.c
//


#include "stdio.h"
#include "stdlib.h"   //malloc function


//lower triangle matrix. 
/*
3  0  0  0
1  4  0  0
6  6  1  0
2  6  8  9
*/

struct LowerTriangleMat
{
    int *A;
    int n;
};

/*
Since this is a diagonal matrix, only a one dimensional array is used to store the data.
Row == Col.   When using set,   Row 1 (and hence Col 1) refers to position 0 in the array.
note [i-1], when i == 1 it is array position 0.

I suppose when looking at arrays it is easier to start wtih Row 1 Col 1 as the upper left position
*/
void Set(struct LowerTriangleMat *m, int i, int j, int x)
{
    //Lower Triangle Matrix Row Major Mapped matrix
    if(i >=j )
    {
        m->A[(i*(i-1)/2)+j-1] = x;     //
    }
}

int Get(struct LowerTriangleMat *m, int i, int j)
{
    if(i >= j)
        return m->A[(i*(i-1)/2)+j-1];  //since this is a diagonal matrix i == j
    else
        return 0;
}

void Display_Matrix(struct LowerTriangleMat m)
{
    for(int i = 1; i<=m.n; i++)
    {
        for(int j=1; j<=m.n; j++)
        {    
            if(i >= j) 
                printf("%d  ",m.A[(i*(i-1)/2)+j-1]);
            else
                printf("0  ");
        }

        printf("\n");
    }
}

int main()
{
    
    struct LowerTriangleMat m;
    int i,j,x;

    printf("Construct n x n matrix. Please specify 'n' : ");
    scanf("%d",&m.n);

    m.A = (int *)malloc((m.n*(m.n+1)/2) * sizeof(int));

    printf("enter all elements (include 0 zero value elements)\n");
    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            
            {
                scanf("%d", &x);
                Set(&m,i,j,x);
            }
        }
    }

    printf("\n\n");
    //Set(&m,1,1,7), Set(&m,2,2,3), Set(&m, 3,3, 4), Set(&m, 4, 4, 8);
    //printf("Element 1,1 %d\n", Get(&m,1,1));

    Display_Matrix(m);

    free(m.A);
    


    return 0;
}