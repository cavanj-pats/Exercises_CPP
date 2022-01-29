//105 leet Construct BST PreOrder InOrder


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
     TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        
        return helper(0, 0, inorder.size() - 1,  preorder, inorder);
    }
    
    private: 
    TreeNode* helper(int preStart, int inStart, int inEnd, vector<int> preorder, vector<int> inorder) {
        
        //base condition
        if (preStart > preorder.size() - 1 || inStart > inEnd) {
            return NULL;
        }
        
        //get the root node with curr preorder element
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        //get inIndex; finding preorder's element's index in inorder
        int inIndex = 0;
        
        for (int i = inStart; i <= inEnd; i++) {
            if(inorder[i] == root->val) {
                inIndex = i; 
            }
        }
        //(next, left of inIndex is the end for left subtree)
        root->left = helper(preStart + 1, inStart, inIndex - 1, preorder, inorder);
        //(prestart + length of left subtree + 1)
        root->right = helper(preStart + inIndex - inStart + 1, inIndex + 1, inEnd, preorder, inorder);
        
        return root;
    }
    //T O(n) S O(n)
public:
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
    vector<int> preorder ={3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);


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