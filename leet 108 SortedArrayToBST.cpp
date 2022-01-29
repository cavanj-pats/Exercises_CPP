//10 leet  SOrted array to BST 
/*
Runtime: 16 ms, faster than 60.49% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
Memory Usage: 24.8 MB, less than 12.79% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// * Definition for a binary tree node.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root;
        //the middle number is the root
        //everything to the left is on the left of root
        //everything to the right is on the right of root
        int x = nums.size();
        if( x == 1 ){ 
            root =  new TreeNode(nums[0]);
            return root;
        }else if (x == 2){
            root = new TreeNode(nums[1]);
            root->left = new TreeNode(nums[0]);
            return root;
        }else if(x==3){
            root = new TreeNode(nums[1]);
            root->left = new TreeNode(nums[0]);
            root->right = new TreeNode(nums[2]);
            return root;
        }
        
        int mid  = x/2;
        int left = mid-1;
        int right = mid+1;
        
        vector<int> l;
        vector<int> r;
        for(int i = 0; i<left; ++i){
            l.push_back(nums[i]);
        }
        for(int i = right-1; i<x; ++i){
            r.push_back(nums[i]);
        }
        
         root = new TreeNode(nums[mid-1]);
         root->left = sortedArrayToBST(l);
         root->right = sortedArrayToBST(r);
        
        return root;
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

int main(){
    vector<int> nums ={-10,-3,0,5,9};
    //vector<int> inorder = {9,3,15,20,7};

    Solution sol;
    TreeNode* root = sol.sortedArrayToBST(nums);


    vector<vector<int> > ans = sol.levelOrder(root);
    
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
    }

    cout << endl; 


    return 0;
    


}