//leet 145. Binary Tree POST order traversal


#include <iostream>
#include <vector>

//for math library some people in discussion are saying
//the define, and two includes
//perhaps it depends on the compiler
/* #define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
*/


using namespace std;

//*
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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root != nullptr){
            
            postorderTraversal(root->left);
            postorderTraversal(root->right);
             ans.push_back(root->val);

        }
        return ans;
    }
    
    vector<int> ans;
};




int main()
{
	
	
	return 0;
	}
	
