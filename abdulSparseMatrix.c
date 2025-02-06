//abdulSparseMatrix.c

#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int i;
    int j;
    int x;
};  //struct Element

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *e;
};  //struct Sparse


//this is an array based sparse matrix
void create(struct Sparse *s)
{
    int i;
    
    printf("Enter Dimensions: ");
    scanf("%d%d",&s->m,&s->n);
    printf("Enter the total Number of non-zero elements: ");
    scanf("%d",&s->num);

    //create space for all the non zero elements entered by the user:
    s->e=(struct Element *)malloc(s->num*sizeof(struct Element));
    printf("Enter the non-zero Elements in order from lowest to highest row, lowest to highest column: ");
    for(i=0;i<s->num;i++)
        scanf("%d%d%d",&s->e[i].i,&s->e[i].j,&s->e[i].x);
};


void display( struct Sparse s)
{
    int i, j, k=0;
    for(i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++)
        {
            if(i==s.e[k].i && j==s.e[k].j)
                printf("%d  ",s.e[k++].x);
            else
                printf("0  ");
        }
        printf("\n");
    }
};

int main()
{
    struct Sparse s;
    create(&s);
    printf("\n");
    display(s);

    free(s.e);
    return 0;
}