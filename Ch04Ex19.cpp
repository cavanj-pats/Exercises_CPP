// Ex19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"


int main()
{
	vector <string> names;
	vector <int> scores;
	string name_input{ "" };
	int score_input{ 0 };
	cout << "Enter Name and Score. Enter (NoName) and (0) to end: ";
	while (cin >> name_input >> score_input) {
		if (name_input != "NoName" && score_input != 0) {
			names.push_back(name_input);
			scores.push_back(score_input);
			cout << "Accepted item index:" << names.size() - 1 << "\n";
		}
		else {
			//exit while
			break;

		}

		cout << "Enter Name and Score. Enter (NoName) and (0) to end: ";

	}
	cout << "Final Item at index:" << names.size() - 1 << "\n\n";
	for (int i = 0; i < names.size(); ++i) {
		cout << "Name, score: " << names[i] << ", " << scores[i] << "\n";
	}

	cout << "\n\n";
	string search{ "" };
	bool found{ false };
	cout << "Enter a name to search: ";
	cin >> search;
	int z{ 0 };
	for (string n : names) {
		if (search == n) {
			found = true;
			cout << "Found " << names[z] << ", " << scores[z] << " at index: " << z << "\n";
			++z;
			break;
		}
		++z;
	}
	if (!found)
		cout << "\nName " << search << " not found.\n";


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
