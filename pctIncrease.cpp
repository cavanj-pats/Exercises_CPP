//percent increase
 #include <stdio.h>

 float calcNewPrice(float oldPrice, float pctIncrease)
 {
    return oldPrice * (1+pctIncrease);
 }   
 
 void getOldNew(float *oldPrice, float *newPrice)
    {
        printf("/nEnter Old Price and New Price to calculate Percent Increase:");
        scanf("%f %f", oldPrice, newPrice);
        return;
    }

 int main()
 {
    float oldPrice= 169.0;
    float newPrice=194.0;
    float pctIncrease = 0.0;
    int choice=0;
    int tryFlag = 0;
    int runOnce ;

    while (choice!=1 || choice !=2)
    {
        printf("Choose Calculate Percentage Increase (1) or Calculate New Price (2). Enter 1 or 2 (-1 to Exit):");
        scanf("%d",&choice);
        if (choice == -1 || choice > 2) {
            printf("\n\nThank you! Goodbye.\n\n");
            return 0;
        }

        runOnce = 0;
        while(choice == 1 && runOnce==0)
        {
            getOldNew(&oldPrice, &newPrice);

            if(oldPrice == 0.0)
            {
                if(tryFlag <2)
                {   
                    printf("/n Old Price cannot be zero! Try again\n"); 
                    tryFlag++;
                }
                else
                {
                    printf("Sorry cannot divide by zero");
                }
            }
            else
            {
                printf("\nPct Increase from %f to %f = %f", oldPrice, newPrice, 100*(newPrice-oldPrice)/oldPrice);
                printf("\n");
                runOnce++;
            }
        }
        while(choice == 2 && runOnce == 0)
        {
            printf("\nEnter Old Price and Percent Increase (in decimal form):");
            scanf("%f %f", &oldPrice, &pctIncrease);
            printf("\nIncreasing %f by %f percent results in a new price: %f\n", oldPrice, pctIncrease, calcNewPrice(oldPrice, pctIncrease));
            runOnce++;
        }
    
    }
        return 0;
}