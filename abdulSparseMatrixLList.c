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
    struct Node *p;
};  //struct Sparse

//Node struct so that we can also create an array of linked lists of Elements
struct Node{
    int col;  //column
    int data;
    struct Node *next;
    struct Node *first;  // i needed a way to set an address that can be queried for the first node in a row
                         //if first is null then there are no nodes in the row or it's not the first node
                         //from this node, you can move using the next pointer
                         //i don't use this for any other node beyond the first node in a row.
};



//this is an array based sparse matrix
void create(struct Sparse *s)
{
    int i, k, mm=0, nn=0, data=0;
    int counter=0;
    
    printf("Enter Dimensions: ");
    scanf("%d%d",&s->m,&s->n);
    //for initial testing
    //s->m = 3;
    //s->n = 3;
    
    printf("Enter the total Number of non-zero elements: ");

    scanf("%d",&s->num);

    //for initial testing
    //s->num = 3;

    //create space for all the non zero elements entered by the user:
    //s->e=(struct Element *)malloc(s->num*sizeof(struct Element));

    //create a one dimensional array to hold the lists. one array of lists
   // struct Node *A[s->m];
    //array declaration reserves the memory.
    s->p = (struct Node*)malloc( s->m * sizeof(struct Node));
    //when the above memory is reserved, the starting address is reserved and it can't be changed
    //
    
    
    struct Node* t;
    struct Node* q;
    //  
    

    printf("Enter the non-zero Elements...\n");
    printf("\nEnter ROW COLUMN and data DATA (ex. 0 1 2):\n");
    for(i=0; i<s->num;i++)
        s->p[i].first = NULL;  //initialize the array of pointers

    for(i=0;i<s->num;i++)
    { 
        
      //using this procedure the nodes can be entered in any order and they'll be inserted into the correct list.  
      scanf("%d%d%d",&mm, &nn, &data);
       // t->col = nn;
        //t->data = data;
        //t->next = NULL;   //change this later

        /*
        if (i == 0)
        {   mm = 1, nn = 2, data = 9;}
        else if(i == 1)
        {   mm = 0, nn = 1, data = 2; }
        else 
        {   mm = 1, nn = 1, data = 4;}
        */
        
        //create a node
            t=(struct Node *)malloc(sizeof(struct Node));  //create a new Node
            t->col = nn;
            t->data = data;
            t->next = NULL;
            t->first = t;  //just a holder for the individual NODE address

        
        if(  s->p[mm].first == NULL)
        {
            //list for this row is empty
            
            
            //s->p[mm]= t;
            s->p[mm].col = nn;
            s->p[mm].data = data;
            s->p[mm].next = NULL;
            s->p[mm].first = t; // s->p[mm].first;

        }
        else{
            q = &s->p[mm];
            //should q become the first node
            if(t->col < q->col)
            {
                t->next = q;
                s->p[mm].first = t;   //first will always point to first node
            }
            else{
                while(q->col < t->col)
                {
                    if(q->next == NULL)
                    {
                        //end of list
                        t->next = q->next;
                        q->next = t;
                        
                        //
                        q=q->next; //will now make while false
                    }
                    else{
                        if(t->col < q->next->col)
                        {
                            t->next = q->next;
                            q->next=t;
                            q=q->next;   //will now make while false
                        }
                        else{
                            q = q->next;
                        }
                    } 
            
            
                    //SortedInsert(&s->p[mm], nn, data);
                }
            }
                 
        }
    }    
    

};

void display( struct Sparse * s)
{
    int i, j, k=0;
    struct Node *p;
    for(i=0;i<s->m;i++)
    {
        p = s->p[i].first;   //this should be the first node of the list for the row
        for (j=0; j<s->n;j++)
        {
            if(p)
            {
                if(p->col == j)
                {
                    printf("%d ",p->data);
                    p=p->next;
                }
                else
                    printf("0 ");
            }
            else
                printf("0 ");
        }
        
        printf("\n");
    }
};






int main()
{
    struct Sparse s;
    create(&s);
    printf("\n");
    display(&s);

    free(s.p);
    return 0;
}