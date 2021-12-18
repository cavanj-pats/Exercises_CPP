//leet 88 merge two sorted arrays


#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for (int i = m; i< m+n; ++i){
            nums1[i] = nums2[i-m];

        }
        sort(nums1.begin(), nums1.end());

        

        /*
        int i=m, j=n;

        while (i+j >0){
            if(i ==0){
                if(j !=0){
                    nums1[i+j-1]= nums2[j];
                    --j;
                }
            }
            else if (j == 0){
                nums1[i+j-1] = nums1[i-1];
                --i;
            }
            
            
            
            
            if(nums2[j-1] > nums1[i-1] && j > 0){
                nums1[i+j-1] = nums2[j-1];
                --j;
            }
            else if (nums2[j-1] == nums1[i-1] && j > 0){
                nums1[i+j-1] = nums2[j-1];
                --j;
            
            }
            if(nums1[i-1] > nums2[j-1] && i>0){
                nums1[i+j-1] = nums1[i-1];
                nums1[i-1]=0;  //need to reset the value in here to zero
                --i;
            } else if(nums1[i-1] == nums2[j-1] && i >0){
                nums1[i+j-1] = nums1[i-1];
                --i;
            }

        }

        return;

        */

        //the last n indexes will have zeroes on nums1



        /*
        vector<int> temp(m+n,0);   

        if ( nums2.size() == 0) return;
        if (m == 0 ) {
            nums1 = nums2; 
            return;
            }


        for(int k=0; k<m+n; ++k){
            if (nums1[i]< nums2[j] && i<m){
                temp[k] = nums1[i];
                ++i;
            } else if(nums2[j] < nums1[i] && j<n){
                temp[k] = nums2[j];
                ++j;
            } else if(i<m){
                temp[k] = nums1[i];
                i++;

            }else if(j<n){
                temp[k] = nums2[j];
                ++j;
            } else{
                temp[k] = 0;
            }
            
        }

        nums1 = temp;
        */
    }
};

int main(){
    vector<int> nums1 = {2,0};
    vector<int> nums2 = {1};
    int n = 1;
    int m = 1;

    Solution sol;

    sol.merge(nums1, m, nums2, n);
    cout << "[";
    for(int n:nums1){
         cout << n ;
        if (n != nums1.back()) cout << ", ";
       
    }
    cout <<"]";

    return 0;

}