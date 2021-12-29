//leet 102. Binary Tree Level Order traversal


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
	
	return 0;
	}
	
