//leet 199 binary tree right side

//accepted at Leetcode
//i was on teh right track but as normal,  teh actual code was much simpler than what i was thinking

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
    vector<int> rightSideView(TreeNode* root) {
        //if the left side is below the right side, need to include those nodes 
        //that are visible from the right side.
        
        vector<int> ans;

        if (root == NULL) return ans;
        
        vector<int> val;
        vector<int> height;

        
        int h = 1;
        //lh = getHeight(temp->left) +1;  //teh plus one normalizes the height with the height vector
        //rh = getHeight(temp->right) +1;

        mapNodeValAndHeightToVectors(val, height, root, h);

        





        return val;
    }
    
private:
    int getHeight(TreeNode* Node){
        int max_height=0;

        if (Node==NULL){
            return 0;
        }
        else
        {
            /* compute the height of each subtree */
            int lHeight = getHeight(Node->left);
            int rHeight = getHeight(Node->right);

            if(lHeight >= rHeight)
                max_height = lHeight;
            else   
                max_height = rHeight;


            return max_height+1;;
        }
    }



  
    void mapNodeValAndHeightToVectors(vector<int> &val, vector<int> &height, TreeNode* root, int h){
        
        if (root == nullptr) return;
        
        if (val.size()<h) val.push_back(root->val);
            
            height.push_back(h);

            mapNodeValAndHeightToVectors(val, height, root->right, h+1);
                        
            mapNodeValAndHeightToVectors(val, height, root->left, h+1);
            
    }


};


int main(){
    TreeNode* n = new TreeNode(5);
    n->left = new TreeNode(1);
    n->left->right = new TreeNode(3);
   // n->left->left = new TreeNode(4);
    n->right = new TreeNode(6);
    // n->right->right = new TreeNode(4);
     n->left->right->right = new TreeNode(4);
     n->left->right->left = new TreeNode(2);

    Solution sol;
    vector<int> ans;

    ans = sol.rightSideView(n);

    for (auto a: ans){
        cout << a <<"," ;
    }
    
    cout << endl;
    cout << "done" << endl;

    return 0;
}