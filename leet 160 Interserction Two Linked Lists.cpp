//leet 160 intersection of two lists
//submitted and accepted
#include <iostream>
#include <unordered_map>

using namespace std;


 //Definition for singly-linked list
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
                
        if (tempA == nullptr || tempB == nullptr) return nullptr;
        //the while condition sets up that if the first node both are equal the while
        //will be bypassed and the return statement at the bottom will return tempA
        //tempA chosen arbitrarily
        while ((tempA && tempB && tempA != tempB) ){
           
           tempA = tempA->next;
           tempB = tempB->next;

            //in the case of non intersecting lists they will both
            //point to nullptr at the same time so will return null here
           if(tempA == tempB) return tempA;
                     
            //re-assign the pointers.  After thsi is done once the intersection
            //point will occur at he same time in each pointer.
           if ( tempA == nullptr) tempA = headB;
           if (tempB == nullptr) tempB = headA;

        }

        return tempA;
    }
};


int main(){
    Solution Sol;
    
    ListNode*  headA = new ListNode(4);
    ListNode* headB = new ListNode(5);
    ListNode* headC = new ListNode(8);
    //headA->val = 4;
    headA->next = new ListNode(1);
    //headA->next->val = 1;
    headA->next->next = headC;
    
    //headB->val  = 5;
    headB->next = new ListNode(6)  ;
    //headB->next->val = 6;
    headB->next->next = new ListNode(1);
    //headB->next->next->val = 1;
    headB->next->next->next = headC;

    //headC->val = 8;
    headC->next = new ListNode(4);
    //headC->next->val = 4;

    /* head->next->next->val = 2;
    head->next->next->next = new ListNode ;
    head->next->next->next->val = 2;
    head->next->next->next->next = new ListNode ;
    head->next->next->next->next->val = 5 ;
    head->next->next->next->next->next = new ListNode;
    head->next->next->next->next->next->val = 6; */

    ListNode* result = Sol.getIntersectionNode(headA, headB);

    cout << "Interserction Node: " << result->val << endl;





    return 0;
}