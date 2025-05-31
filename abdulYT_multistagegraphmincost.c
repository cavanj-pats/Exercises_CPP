//dynamic programming
//multi stage graph minimum cost

#include <stdio.h>
#include <limits.h>


#define I INT_MAX

void displaypath(int path[], int stages)
{
    for(int i=1;i<=stages;i++)
    {
        printf("%d,",path[i]);
    }
    printf("\n");

    return;
}


int main()
{

    int stages=4;
    int min= I;
    int n=8;
    int cost[9], d[9], path[9] ;
    //cost is the min cost remaining at each vertex
    //d is the direction or next destination upon departing a vertex that results in min cost
    //path
    //n is the total number of vertices
    //min is  placeholder for the min costs while looping
    //stages
    //Cost Adjacency Matrix is:
    int c[9][9] = {{0,0,0,0,0,0,0,0,0},
                    {0,0,2,1,3,0,0,0,0},
                    {0,0,0,0,0,2,3,0,0},
                    {0,0,0,0,0,6,7,0,0},
                    {0,0,0,0,0,6,8,9,0},
                    {0,0,0,0,0,0,0,0,6},
                    {0,0,0,0,0,0,0,0,4},
                    {0,0,0,0,0,0,0,0,5},
                    {0,0,0,0,0,0,0,0,0}};
                    //starting vertex is row   ending vertex is column  data is cost
                    //cost adjaceny data is read only once enterdd to represent the subject graph



    cost[n]=0;   //the cost from the end vertex to the end vertex is zero
    for(int i = n-1; i>=1; i--)
    {
        min = I;
        for(int k=i+1;k<=n;k++)
        {
            //first time through, k = 8 and cost[8] is zero.  just set it above as n==8
            //cost[7][8] == 5

            //second time i = 6, k=7, c[6][7] = 0;


            if(c[i][k]!=0 && c[i][k]+cost[k]<min)
            {
                min = c[i][k]+cost[k];
                d[i]=k;
            }
        }
        cost[i]=min;
    }
    
    path[1]=1;
    path[stages]=n;
    for(int i=2;i<stages; i++)
    {
        path[i]=d[path[i-1]];
    }

    displaypath(path,stages);


    return 0;

}