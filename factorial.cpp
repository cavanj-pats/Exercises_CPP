#include <iostream>


using namespace std;

int factorial (int i);
int kCombinations (int n, int k);

int main()
{
	int num, n, k ;
	
	
	cout <<"Please enter integer and I will calculate Factorial of it:"<< endl<<endl;
	cin >> num;
	cout << "The factorial of " << num << " is= " << factorial(num) << " \n" ;
	cout<<"\n\nEnter two integers for n, k combination calculations  ";
    cin >> n >> k;
    cout << "Result: "<< n << " items taken "<< k << " at a time can be taken in "<< kCombinations(n,k) << " combinations\n";



	
	return 0;
	}
	
int factorial (int num){
    int factRes = 1;
    for (int i=2; i<=num;i++)
        factRes *= i;
    return factRes;
}

int kCombinations(int n, int k){
    return factorial(n)/(factorial(k)*factorial(n-k));
}