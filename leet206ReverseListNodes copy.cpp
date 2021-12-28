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
        if (!head || !(head -> next)) {
            return head;
        }
        ListNode* node = reverseList(head -> next);
        //the first time it gets here node = the tail node and head is the node before tail


        head -> next -> next = head;  //
        head -> next = NULL;
        return node;  //keeps returning a copy of itself for each unravel

        
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
        cout << temp->val << ", " ;
        temp = temp->next;
    }

    cout << endl<< "After reverse: " << endl;

    temp = sol.reverseList(head);

    while (temp != nullptr){
        cout << temp->val << ", " ;
        temp = temp->next;
    }


    return 0;
}