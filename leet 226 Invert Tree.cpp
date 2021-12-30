//leet 226.Invert Binary Tree 
//leet 226 Invert Tree.cpp
//2021-12-29


#include <iostream>
#include <vector>
#include <queue>

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
	
