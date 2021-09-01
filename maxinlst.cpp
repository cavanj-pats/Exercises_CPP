//does not work with printf.  must be missing an include....
#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;


int maxinlst(int lst[], int size){
    int tmpMax;
    for(int i=0; i<size;i++){
        if (i==0) tmpMax=lst[i];
        if (i>0 && lst[i]>tmpMax) tmpMax=lst[i];
    }
    return tmpMax;
}

/*
int main()
{
	
	int lst[] = {-19, -3, 20, -1, 25, -25};

    printf( "%i", maxinlst(lst,6));

	

	return 0;
}
	
*/