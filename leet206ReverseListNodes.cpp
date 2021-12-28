//206 reverse nodes in a list

#include <iostream>
#include <vector>

using namespace std;

 // Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };





class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* node;
        
        if (!head || !head->next){
            return head;   //if either of these is null then return the node.  this is the new head
        }
        node = reverseList(head->next);
        //now need to reset all the pointers so they are reversed
         
         //this is where the reversing will take place
         head->next->next = head;
         head = head->next;
         head->next->next = nullptr;
         //each time function recurses head gets the value of the recursion when it was originally entered
         
        
        return node;
    }
};





int main(){
    Solution sol;
    ListNode* head = new ListNode ;
    head->val = 1;
    head->next = new ListNode ;
    head->next->val = 2;
    head->next->next = new ListNode  ;
    head->next->next->val = 3;
    head->next->next->next = new ListNode ;
    head->next->next->next->val = 4;
    head->next->next->next->next = new ListNode ;
    head->next->next->next->next->val = 5 ;
    head->next->next->next->next->next = new ListNode;
    head->next->next->next->next->next->val = 6;

    ListNode* temp = head;

    while (temp != nullptr){
         temp->next == nullptr ? cout << temp->val :cout << temp->val << ", " ;
        temp = temp->next;
    }

    cout << endl<< "After reverse: " << endl;

    temp = sol.reverseList(head);

    while (temp != nullptr){
        temp->next == nullptr ? cout << temp->val :cout << temp->val << ", " ;
        temp = temp->next;
    }
    cout << endl;



    return 0;
}