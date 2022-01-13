// leet 240 search 2D Matrix
//the code ran and was accepted.  better than 30% for run time.
//could have been better with the complicated code i was trying.

//1/12/2022

#include <iostream>
#include <vector>

using namespace std;


//approach
// search the diagonals to determine what portion of the matrix target resides in

bool binary_search(int, vector<int>&, int);



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool found = false;
        int m = matrix.size();
        int n = matrix[0].size()-1;

        for (int i=0; i<m ; ++i){
            if(target == matrix[i][0] || target == matrix[i][n]) {
                found = true;
                return found;
            }
            else if (target < matrix[i][n]){
                
                found = binary_search(target, matrix[i], n);
            }
            if (found) return true;
        }

        return false;


/*
        int UL = 0;
        int mid = matrix[0].size()/2;
        int LR = matrix[0].size() - 1;

        while ((LR - UL) >1 ){
            if (target == matrix[mid][mid] || target == matrix [UL][UL] || target == matrix[LR][LR])
                return true;
            else if (target < matrix[mid][mid]){
                LR = mid;
                mid = (LR+UL)/2;
            } 
            else  {
                UL = mid;
                mid = (LR+UL)/2;
            }


        }
        
        int i = 0 ;
        int j = matrix[0].size()-1;
        int m = j;
        int k= 0;
        if (i < UL) k = UL;
        //the upper right search
        while (i <= m ){
            //i is row
            //j and k are column positions

            
            
            if (target == matrix[i][k] || target == matrix[i][j]) return true;
            
            ++k;
            --j;
            if (k>j){
                //reset
                ++i;  //index to next row
                j = matrix[0].size()-1;
                if (i < UL){
                    k = UL;
                }
                else{
                    k = 0;
                }
            }

        }

        return false;

        */

/*
        found = searchHelper(matrix, target, 0, UL, LR, UL, LR);
        if (found) return found;
        found = searchHelper(matrix, target, UL, 0, LR, UL, LR);
        
        return found;
    */    
    }
        
        
};




bool binary_search( int val, vector<int>& srtArr, int srtArrSize){
    int low, high, mid;
    int ind;
    int counter=0;
    bool found = false;
    low = 0;
    high = srtArrSize;
    //if (srtArrSize == 0 && srtArr[0]== val) return 0;

    while (( found == false) && (low<=high) ){
       // counter++;
        mid = (low + high)/2;
        if (srtArr[mid] == val){
            ind = mid;
            found = true;
            return found;   //just stop searching
        }
        else if (val < srtArr[mid])
            high = mid -1;
        else //val > srtArr[mid]
            low = mid + 1;

        
    }
    return found;
    
    /*
    if (found == true)
        return ind;
    else
        return -1;
    
   //return counter;
    */
      
}



void printIntVector(std::vector<int> v){
    std::cout << "[";
    for(int i = 0; i<v.size(); ++i){
        i==v.size()-1 ? std::cout << v[i] : std::cout << v[i] << ", ";
    }
    std::cout << "]";
    std::cout << endl;

}


int main(){

    vector<vector<int>> nums = {{-5}};
    //{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    
    //{{1,2,3},{4,5,6},{7,8,9}};

    //{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}}

    Solution sol;

    //cout << "[";
    for(auto n:nums){
        printIntVector(n);
        n == nums[nums.size()-1] ? std::cout <<"" : std::cout << ", ";
    }
    std::cout << endl;

    int v = -5;

    std::cout << "Is "<< v << " in the matrix? "<<sol.searchMatrix(nums, v)<< endl;
    v=20;
    std::cout << "Is "<< v << " in the matrix? "<<sol.searchMatrix(nums, v)<< endl;
    v=27;
    std::cout << "Is "<< v << " in the matrix? "<<sol.searchMatrix(nums, v) << endl;

    

    return 0;
}