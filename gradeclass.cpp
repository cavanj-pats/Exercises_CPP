//gradeclass.cpp
//Grade Classification Lab 
#include <iostream>

using namespace std;

int main(){
	double grade1, grade2;
	
	cout << "Please enter 2 grades, separated by a space:";
    cin >> grade1 >> grade2;
    if (grade1<60 && grade2<60)
    	cout << "Student Failed:(\n";
    else if(grade1>=95 && grade2>=95)	
    	cout <<"Student Graduated with Honors:)\n";
	else
		cout <<"Student Graduated!\n";
    
        
    cout << "\n";
        
	return 0;
}
