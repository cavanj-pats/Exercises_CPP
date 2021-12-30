//leet74 search matrix


#include <iostream>
#include <vector>


using namespace std;

bool binary_search( int val, vector<int> srtArr);


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int>rowTemp;
        int m = matrix.size(); //number of rows
        int n = matrix[0].size();  //number of columns

        if (target < matrix[0].front() || target>matrix[m-1].back()) return false;
//convert 2D to 1D and send to Binary search algorithm
        for(int x = 0; x<m; ++x){
            for(int y = 0; y<n; ++y){
                rowTemp.push_back ( matrix[x][y]);
            }
        }

        return binary_search(target, rowTemp);
/*
        int i=0;
        int j = m-1;
        int mid = (i+j)/2;

        while (i <= j){
            int frntFrnt = matrix[i].front();
            int frntBack = matrix[i].back();
            int backFrnt = matrix[j].front();
            int backBack = matrix[j].back();

            if (target < frntFrnt) return false;
            if (target == frntFrnt) return true;
            if (target == frntBack) return true;
            if (target > frntBack){
                ++i;
            }else
            {
                rowTemp = matrix[i];
                break;
            }

            if (target > backBack) return false;
            if (target == backFrnt && target == backBack) return true;




            
            if (target == matrix[i].front() || target == matrix[j].back()) return true;
            
            //easy to implement two pointers
            if (target < matrix[i].back()) {
                rowTemp = matrix[i];
                break;
            }
            

            if (target >= matrix[j].front() && target < matrix[j].back()){
                rowTemp = matrix[j];
                break;
            } 

            
            ++i; //if it gets here we know we can index i
            --j;  //if it gets here we can index j
*/
            //i really wanted to implement a binary search to find the rowTemp
            //but the if then structure started to get complicated.

            /*
            if(target > matrix[i].back() && target < matrix[mid].back()){
                    ++i;
                    j=mid; 
                    mid = (i+j)/2;
            } else if(target > matrix[mid].back() && target < matrix[j].back()){
                    i=mid;                    
                    mid = (i+j)/2;
                    if (mid ==i && mid < j) ++mid;
            } else if (target == matrix[mid].back()){
                    return true;
            }else if (target < matrix[i].back()){
                mid = i;
                j = i;
            }
            */
      //  }
            //the below line is only needed for implementing the binarysearch technique for row temp
            //rowTemp = matrix[mid];  

                   

     //   return binary_search(target, rowTemp);
        
    }
};

bool binary_search( int val, vector<int> srtArr){
    int low, high, mid;
    int ind;
    int counter=0;
    bool found = false;
    low = 0;
    high = srtArr.size();
    while (( found == false) && (low<=high) ){
        counter++;
        mid = (low + high)/2;
        if (srtArr[mid] == val){
            ind = mid;
            found = true;
            return found;
           // return ind;   //just stop searching
        }
        else if (val < srtArr[mid])
            high = mid -1;
        else //val > srtArr[mid]
            low = mid + 1;

        
    }
    return found;

          
}

int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target =5;
    Solution sol;
    cout << sol.searchMatrix(matrix, target) << endl;
    //cout << sol.searchMatrix(matrix, 21) << endl;
    

    return 0;
}