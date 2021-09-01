#include <iostream>
#include <string>
#include <math.h>


using namespace std;

float priceDiscounted(float price1, float price2, char club){
    if (price1 < price2)
		if ( club=='Y' || club =='y')
			return (0.5 * price1 + price2)*0.9;
		else
			return (0.5 * price1 + price2);
	else
		if ( club=='Y' || club =='y')
			return (0.5 * price2 + price1)*0.9;
		else
			return (0.5 * price2 + price1);
}


int main()
{
	
	float price1, price2, tax, discountedPrice;
	char club;
	
	cout <<"Enter price of the first item: ";
	cin >> price1;
	cout <<"Enter price of the second item: ";
	cin >> price2;
	cout << "Does customer have a club card? (Y/N): ";
	cin >> club;
	cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> tax;
	//printf("price1 round = %2.2f \n", round(price1));

	discountedPrice = priceDiscounted(price1, price2, club);
	//cout << "Base Price = " << round((price1+price2)*100)/100 << endl;
    printf("Base price = %2.2f \n", price1+price2);
    printf("Price after discounts = %2.2f \n",discountedPrice);
    printf("Total price = %2.2f \n", round(discountedPrice * (1+tax/100)*1000)/1000);
// the final submission that was 5 or 5 correct required round to multiply and divide by 1000 not 100.

	
	
	
	return 0;
	}
	
