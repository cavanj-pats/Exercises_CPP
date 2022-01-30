//leet 113 Path Sum II

//accepted at Leetcode
/*
Runtime: 12 ms, faster than 68.16% of C++ online submissions for Path Sum II.
Memory Usage: 19.8 MB, less than 81.48% of C++ online submissions for Path Sum II.
*/

#include <iostream>
#include <vector>


using namespace std;


//* Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left; 
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };



class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> aV;
      //  vector<vector<int>> result;

        findPath(ans, root, aV, targetSum);

        for (auto a: ans){
            int runningSum = 0;
            for (int i = 0; i<a.size(); ++i){
                runningSum += a[i];
            }
            //if(runningSum == targetSum) result.push_back(a);
        }
        return ans;   
    }
    
    
private:
    
  
    void findPath(vector<vector<int>> &ans, TreeNode* root, vector<int> &a, int sum){
        
        
        if (root == nullptr) return;
        a.push_back(root->val);
        if (!(root->left) && !(root->right) && sum == root->val)
            ans.push_back(a);

         findPath(ans, root->left,a, sum - root->val );
         findPath(ans, root->right, a, sum - root->val);
         a.pop_back();   
            
             
            
    }


};


int main(){
    TreeNode* n = new TreeNode(5);
    n->left = new TreeNode(4);
   // n->left->right = new TreeNode(3);
    n->left->left = new TreeNode(11);
    n->right = new TreeNode(8);
    n->right->right = new TreeNode(4);
     n->left->left->right = new TreeNode(2);
     n->left->left->left = new TreeNode(7);
     n->right->left = new TreeNode(13);
     n->right->right->right = new TreeNode(1);
     n->right->right->left = new TreeNode(5);

//[5,4,8,11,null,13,4,7,2,null,null,5,1]
    Solution sol;
    vector<vector<int>> ans;

    ans = sol.pathSum(n,22);

    for (auto a: ans){
        for (int i = 0; i<a.size(); ++i){
            cout << a[i] <<"," ;
        }
        cout << ", ";
    }
    
    cout << endl;
    cout << "done" << endl;

    return 0;
}