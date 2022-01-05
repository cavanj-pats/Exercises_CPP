//leet 112 Binary Tree Path SUm
// leet 112 Binary Tree Path Sum.cpp


#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>>

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
     bool findTarget(TreeNode* root, int k) {
         vector<int> values;
         vector<int> &v = values;
         vector<int> ans;

         inOrderVectorFill(root, v);
         //sort(v.begin(), v.end());

        ans = twoSum(v, k);

        if (ans.size() != 0)  return true;

        return false;
    }
     
     
     
    // in order push tree values onto vector then use old TwoSum function.
    void inOrderVectorFill(TreeNode* root, vector<int> &vValues ) {
        if (root != nullptr){
            vValues.push_back(root->val);
            inOrderVectorFill(root->left, vValues );
            inOrderVectorFill(root->right, vValues);            
        }
    }

     vector<int> twoSum(vector<int>& nums, int target) {       
        vector<int> ans;
        bool solutionFound = false;
               
        ans.clear();
        sort(nums.begin(), nums.end());
        int x = 0;
        int y=nums.size()-1;
       
        while (x < y){
            if(nums[x] + nums[y] <  target){
                ++x;
            }
            else if (nums[x]+ nums[y] >target){
                --y;
            } else{
                ans.push_back(nums[x]);
                ans.push_back(nums[y]);
                solutionFound = true;
                while (x < y && (nums[x] == nums[x+1])) ++x;
                while (x < y && (nums[y] == nums[y-1])) --y;
                ++x; --y;
            }        
                
        }
        return ans;
    }


    bool hasPathSum(TreeNode* root, int targetSum) {

         map<bool, int> response;
         //map<bool, int> &response = r;
         response.insert(response.begin(), std::pair<bool, int> (false,0)  );
         response.insert(response.begin(), std::pair<bool, int>(true, 0) );
        
        inorderSum (root, 0, targetSum, response);

        return response[true] > 0;

    }


    
    
    void inorderSum(TreeNode* root, int runningSum, int target, map<bool, int> &response) {
        if (root != nullptr){
            runningSum += root->val;
            inorderSum(root->left, runningSum, target, response);
                   
            inorderSum(root->right, runningSum, target, response);
            
        } else{
            if (runningSum == target) 
                response[true]++;
        }

        response[false]++;
    }
    
    // ****************
     TreeNode* invertTree(TreeNode* root) {
        
        invertHelper(root);

        return root;
    }

    void invertHelper(TreeNode* root){
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        if (root->left) invertHelper(root->left);
        if (root->right) invertHelper(root->right);

        return;
    }
    //****************************************************8
    bool isSymmetric(TreeNode* root) {
        //I believe if I determine the height and node count on each subtree and if they are equal return TRUE    
        
       bool ans = symmetricHelper(root->left, root->right);

        return ans;

    }

    bool symmetricHelper(TreeNode* left,  TreeNode* right){
        if (!left && !right){
            return true;
        }
        else{
            if((!left && right) || (left && !right)) return false;  //unbalanced tree
            if( symmetricHelper (left->left, right->right) && symmetricHelper(left->right, right->left)) return true;
        }
        
        return false;
    }
    




    int maxDepth(TreeNode* root) {
        int height = 0;

        if(root == NULL){
            return 0;
        } else{
            
            int leftHeight = maxDepth(root->left); 
            int rightHeight = maxDepth(root->right);
            if ( leftHeight > rightHeight)
                height = leftHeight;
            else
                height = rightHeight;
          
        }
        return height + 1;


    }
    




    
    vector<vector<int> > levelOrder(TreeNode* root) {
        //1. Print the root node
        //2. print its left and right nodes
        //3. traverse left(?)  don't print this node but GOTO 2.
        //4. traverser right  don't print this node but GOTO 2.
        //5. repeat 3 and 4 recursively

        queue<TreeNode*> que;
        vector<int> levelNodes;
        vector<vector<int> > result;

        if (!root) return {};   //*** I don't think this is needed
        que.push(root);
        int count = 1;

        while (!que.empty()){
            TreeNode* q = que.front();
            if (q->left) que.push(q->left);
            if (q->right) que.push(q->right);
            levelNodes.push_back(q->val);            
            que.pop();
            
            //I was very much on teh right track
            //i missed what keeping track of "count" would do.
            //notice how count is still being indexed even though the expression may be false
            //when the expression evaluates as true,  the results are pushed and the level or row vector is cleared.
            //THEN the count is recalculated to be the size of the next level or row.
            if(--count == 0){
                result.push_back(levelNodes);
                levelNodes.clear();
                count = que.size();
                //https://www.geeksforgeeks.org/level-order-traversal-line-line-set-3-using-one-queue/
                //https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/33709/Short-8ms-C%2B%2B-solution-with-queue4

            }
                            
                
            

            
        }

        return result;
    }


};




int main()
{
	TreeNode node(3);
    node.left = new TreeNode (9);
    node.right = new TreeNode (20);
    node.left->right = new TreeNode (11);
    node.right->left = new TreeNode (15);
    node.right->right = new TreeNode (7);

    TreeNode* root = &node;
    Solution sol;
    
    cout << "Path Sum = 30: "<< sol.hasPathSum(root, 30 )<< endl<<endl;
    
    vector<vector<int> > ans = sol.levelOrder(root);
    
    TreeNode* swapped = sol.invertTree(root);

    for(vector<int> t : ans){
         cout << "[";
        for(int n=0; n<t.size(); ++n){
            cout << t[n] ;
            if (n != t.size()-1) cout << ", ";
        
        }
    if(t == ans.back()) 
        cout <<"]";
    else
        cout << "],";

    cout << endl; 

    }

    cout << "height: " << sol.maxDepth(root) << endl;
    cout << "Symmetric Tree: " <<  sol.isSymmetric(root) << endl;

	
	return 0;
	}
	