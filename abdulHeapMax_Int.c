


#include <stdio.h>

void insert(int H[], int n)
{
    int i = n, temp;
    temp = H[i];

    while(i>1 && temp>H[i/2])
    {
        H[i]=H[i/2];
        i = i/2;
    }
    H[i]= temp;

}

int delete (int A[], int n)
{
    int i, j, x, temp, val;
    //n is size of array  position of last element
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;  //keep the deleted item in the last place
    i = 1; j = i*2;
    while (j < n-1)
    {
        if(A[j+1] > A[j])
            j = j+1;
        if(A[i]<A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i=j;
            j = j*2;

        }
        else
            break;
    }

    return val;
}


int main()
{
    int H[]={0,10, 20, 30, 25, 5, 40, 35}  ;
    //above is simply an array.
    //once inserted in a Heap it becomes a Heap (or an array
    //organized in a Heap)

    //after Heap insert  40,25,35,10, 5, 20, 30

    int i;
    for (i = 2; i<=7; i++)
        insert(H, i);

    for(i = 1; i<=7; i++)
        printf("%d ",H[i]);

    printf("\nDeleted value is: %d\n", delete(H,7));

    //if you don;t want to print the last element,which is the deleted element, reudce 7 to 6
    for(i = 1; i<=7; i++)
        printf("%d ",H[i]);

    //try heapsort
    for (i=7; i>1; i--)
        delete(H,i);
    
    printf("\n");

    for(i = 1; i<=7; i++)
    printf("%d ",H[i]);    

    return 0;

}