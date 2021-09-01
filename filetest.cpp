//filetest.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
/*
void openInputFile(ifstream& inFile);

void csv_export(string data[][10], int records,int columns, string filename);

void csv_import(string data[][10], int columns, int *records, string filename);

void openInputFile(ifstream& inFile){
    string filename;
    cout << "Enter a file name: ";
    cin >> filename;
    inFile.open(filename);
    while(!inFile){
        cout << "FILE DID NOT OPEN. PLS CONFIRM FILE NAME. ";
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
}


void csv_export(string data[][10], int records,int columns, string filename){
    ofstream outFile(filename);
    for(int i=0; i<records;i++){
        for(int j=0; j<columns; j++){
            outFile << data [i][j] ;
            if (j<columns-1)
                outFile << ",";
        }
        outFile << "\n";
    }


    outFile.close();
}
*/

void csv_import(string data[][10], int columns, int *records, string filename);

void csv_import(string data[][10], int columns, int *records, string filename){
    int k=0;
    int &rec = *records;
    int pos =1;
    int j;
    int length=0;
    string temp;
    ifstream inFile;
    inFile.open(filename);
    while(!inFile){
        cout << "FILE DID NOT OPEN. PLS CONFIRM FILE NAME. ";
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
    
    for (int i=0; i<rec; i++){
        j=0;
        k=0;
        getline(inFile,temp);  //put each line from file into a temp string
        length = temp.length();
        pos = temp.find(',');
        while (pos!=string::npos){   //if the ',' is not found, exit while            
                data[i][j] = temp.substr(k, pos-k); //each data element is a substring
                k=pos+1;  //move one character beyond the ',' for the next search
                pos = temp.find(',', k);  //search for the ',' in the remaining portion of the string
                j++;
            }
            data[i][j]= temp.substr(k, length-k);  //this is the final substring to '\n'
               
                        
            

        
        
        
    }


}


/*
int main(){
  //  ofstream outFile("filetest.txt");
  //  outFile << "Hello.\n World" ;
   
   /*
   //input test
   vector<int> v;
   int temp;
   ifstream inFile;
   openInputFile(inFile);
   while(inFile >> temp){
        v.push_back(temp);
   }

   double sum=0;
   for (int item : v)
       sum += item;

       cout << "The average of the data in the file is: " <<  sum /v.size() << endl;
    */

//string data[10][10] = {{"aspen","olmsted","aspen@pleasedonotemail.com"},{"sally","jones","sally@gmail.com"},{"fred","smith","fsmith@aol.com"}};

//csv_export(data,3,3,"customers.csv");

/*
string data[10][10];
for(int i=0; i<4; i++){
    for(int j=0; j<3;j++){
        data [i][j] = "Jim";
    }
}
int rec =4;
int *recPtr = &rec;

csv_import(data, 3, recPtr,"customers.csv");

for(int i=0; i<rec; i++){
    for(int j=0; j<3;j++){
        cout << data[i][j] ;
        if (j<2) cout << ", ";
    }
    cout << "\n";

}




    return 0;

}

*/