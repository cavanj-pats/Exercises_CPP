//abdulKruskalsMST.c
/*
1. Take smallest edge.
2. keep taking successive smallest edge
3. Cycles are not allowed. Keep checking if an edge leads to a cycle. if it does, do not include it
    flag it so that it won't be included.
*/
#include <stdio.h>
#include <limits.h>


#define I INT_MAX
//edges.  First Row has first vertex, second row second vertex, third row is "cost"
int edges[3][9]={{1, 1, 2, 2, 3, 4, 4, 5, 5},
                 {2, 6, 3, 7, 4, 5, 7, 6, 7},
                {25, 5, 12, 10, 18, 16, 14, 20, 18}};

int set[8] = {-1, -1, -1, -1, -1, -1, -1, -1};  //he says 8 but there are 0
//set is a data structure to check for circular relationship

int included[9]={0}; //is an edge to be included or not
int t[2][6];  //solution goes here

void _union(int u, int v)
{
    if(set[u]<set[v])
    {
        set[u]=set[u]+set[v];
        set[v]=u;
    }
    else
    {
        set[v]+=set[u];
        set[u]=v;
    }
}

int find(int u)
{
    int x = u;
    while(set[x]>0)
        x = set[x];

    return x;
}


int main()
{
    int i=0, j, k, n=7, e=9, min, u, v;
    while(i<n-1)
    {
        min=I;
        for(j=0; j<e;j++)
        {
            if(included[j]==0 && edges[2][j]<min)
            {
                min=edges[2][j];
                k=j;
                u=edges[0][j];
                v=edges[1][j];
            }
        }
        if(find(u)!=find(v))
        {
            t[0][i]=u;
            t[1][i]=v;
            _union(find(u),find(v));
            i++;
        }
    }
    included[k]=1;


    return 0;
}