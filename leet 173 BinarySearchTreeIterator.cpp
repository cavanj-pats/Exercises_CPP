//leet 173 Binary search Tree Iterator
// leet 173 Binary Search Tree Iterator

/*
https://leetcode.com/problems/binary-search-tree-iterator/discuss/1430547/C%2B%2B-Simple-Solution-using-Stack-O(h)-Time-Complexity-(-with-Diagrammatic-Explanation-)
*/
/*
We could have easily done this question by using inorder traversal and storing it in a vector after that 
iterating every index of vector for next() value and if the index is equal to vector size then hasnext() 
becomes false else it would be true.

But in question, it is given that we have to do it in 0(h) memory, where h is the height of the tree. 
So now we will make use of the stack and instead of inorder traversal, we would use partial inorder traversal 
so that at any instant of time the stack contains elements equal to the height of the tree.

Step 1: We will push the left part of the tree into a stack which is 7 and then 3 is inserted. Now is next() 
is called 3 is stored as the top and then poped now we will push the right of 3 but it does not contain any so 
we just return the top->val i.e. 3.

Step 2: We will now pop() 7 from the stack and see if it has the right children yes it has so we push 15 and 
then 9 into the stack. Observe here you'll see at a time stack contains elements equal to the height of the tree.

Step 3: Now 9 is poped and 9 does contain any right child so we move on 15. If hasnext() is called it would return 
true as traversal is still left and the stack is also not empty.

Step 4: Now 15 is poped and checked if it has the right child yes it has i.e. 20 so 20 is pushed inside the stack.

Step 5: Lastly 20 is poped and returned and after that is hasnext() is called it will return false as there are 
no more elements or children inside the stack.

*/
/*
Success
Details 
Runtime: 20 ms, faster than 98.18% of C++ online submissions for Binary Search Tree Iterator.
Memory Usage: 24.2 MB, less than 54.82% of C++ online submissions for Binary Search Tree Iterator.
*/

/*
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.
*/

/*
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary 
search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is 
given as part of the constructor. The pointer should be initialized to a non-existent number smaller 
than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, 
otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() 
will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number
 in the in-order traversal when next() is called.
*/

/*
// leet 173 Binary Search Tree Iterator

/*
https://leetcode.com/problems/binary-search-tree-iterator/discuss/1430547/C%2B%2B-Simple-Solution-using-Stack-O(h)-Time-Complexity-(-with-Diagrammatic-Explanation-)
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        partialInorder(root);
    }
    
    void partialInorder(TreeNode* root){
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* top = s.top();
        s.pop();
        partialInorder(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        partialInorder(root);
    }
    
    void partialInorder(TreeNode* root){
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* top = s.top();
        s.pop();
        partialInorder(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */