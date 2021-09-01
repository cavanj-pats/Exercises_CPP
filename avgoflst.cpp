//does not work with printf.  must be missing an include....
#include <iostream>
#include <cstdio>
#include <iomanip>


using namespace std;


float avgoflst(int lst[], int size){
    float tmpVal=0.0;
    for(int i=0; i<size;i++){
        tmpVal += (float) lst[i];
     }
    
    return tmpVal /(float) size;
}

/*
int main()
{
	
	int lst[] = {19, 2, 20, 1, 0, 18};
    printf( "%3.0f", avgoflst(lst,6));

	

	return 0;
}
	
*/