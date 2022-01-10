//leet 701 insert BST
//2021-12-30


#include <iostream>
#include <vector>
#include <queue>
#include <map>

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
   bool isValidBST(TreeNode* root) {
        
        
        if (!root) return true;
        int rootVal = root->val;

        //the problem is defined such that the values of the left subtree are less than root
        //and values of right subtree are greater than right subtree

        map<bool, int> response;
         //map<bool, int> &response = r;
         response.insert(response.begin(), std::pair<bool, int> (false,0)  );
         response.insert(response.begin(), std::pair<bool, int>(true, 0) );
        /*
        BSTValidLeft(root->left, response, rootVal);
        if (response[false] > 0 ) return false;
        BSTValidRight(root->right, response, rootVal);
        if (response[false] > 0 ) return false;

        isValidBSTHelper( root, response);
        */

        isValidBSTPre(root, response, rootVal);

        if(response[false] > 0) return false;
        return true;

        
        
        
    }

   void isValidBSTPre(TreeNode* root, map<bool, int> &response, int rootVal){
       //if root left exist and is smaller than root
       // if root right exists and is greater than rootval

        if(!root) return;
        if(!root->left){

        } 
        else {
            if(root->left->val < root->val){
                BSTValidLeft (root->left, response, root->val);
                isValidBSTPre(root->left, response, root->val);
            }
            else{
                response[false]++;
            }
        }

        if (!root->right){

        }
        else{
            if(root->right->val > root->val){
                BSTValidRight(root->right, response, root->val);
                isValidBSTPre(root->right, response, root->val);
            }
            else{
                response[false]++;
            }
        }

   } 
   
   void isValidBSTHelper(TreeNode *root, map<bool, int> &response){
       if (root == nullptr) response[true]++;
        if (root->left != nullptr) {
            if (root->left->val < root->val){
                 isValidBSTHelper(root->left, response);
            }
            else{
                response[false]++;
            }
        }
        //else{
        //    return true;
        //}
        
        if (root->right != nullptr){
            if(root->right->val > root-> val){
                isValidBSTHelper(root->right, response);
            }
            else{
                response[false]++;
            }
        }
       // else
        //{
        //    return true;
        //}
   }
   
   void BSTValidLeft(TreeNode* root, map<bool, int> &response,  int rootVal){
       if (!root) return;
       if (root->val >= rootVal) response[false]++;
       BSTValidLeft(root->left, response, rootVal);
       BSTValidLeft(root->right, response, rootVal);
   }

   void BSTValidRight(TreeNode *root, map <bool, int> &response, int rootVal){
       if(!root) return;
       if (root->val <= rootVal) response[false]++;
       BSTValidRight(root->left, response, rootVal);
       BSTValidRight(root->right, response, rootVal);
   }
   
   
   
   
   TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = root;
        TreeNode* prev = root;
        
        
        if (root == nullptr) {
            root-> val = val;
            return root;
        }
        
        while (temp !=nullptr){
            prev = temp;
            if ( val < temp-> val){
                temp = temp->left;
                
            }
            else{
                temp = temp->right;
                
            }
        }
        
        
        if(val < prev->val) {
            prev->left = new TreeNode (val);
        } 
        else{
            prev->right = new TreeNode (val);
        }
        
        return root;
        
    }
   
   
   
   
   //********************************************
   TreeNode* searchBST(TreeNode* root, int val) {
        //find the node in the tree with val
        
        if (val == root->val) return root;
        if( val < root->val){
            if (root->left != nullptr){ 
                return searchBST(root->left, val);
            }
            else{
                //not found
                return nullptr;
            }
        }
        else{
            if (root->right != nullptr){
                return searchBST(root->right, val);
            }
            else{
                return nullptr;
            }
        }
        
    }
   
   
   
   
   //**********************************************
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
	
