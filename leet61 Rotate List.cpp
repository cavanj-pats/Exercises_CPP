//leet61 Rotate Right
// rotate a linked list to the right k times

#include <iostream>

using namespace std;


 //Definition for singly-linked list
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

void oneRight(ListNode*, ListNode*, ListNode*, int k);

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* newHead = new ListNode;

        oneRight(head, temp, newHead, k);

        return newHead;

    }
};


void oneRight(ListNode* head, ListNode* temp, ListNode* newHead, int k){
       
    if (temp->next->next == nullptr ){
        
        newHead->val = temp->next->val;
        newHead->next = head;
        
        temp->next = nullptr;
        head = newHead;
        temp=newHead;
        ;
      
    }
     
       
        
           
            oneRight(head, temp->next, newHead, k);
            
        
        
    
      
    return;

}



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

    ListNode* temp = head;

    while (temp != nullptr){
        cout << temp->val << ", " ;
        temp = temp->next;
    }

    cout << endl<< "After two rotations: " << endl;

    temp = sol.rotateRight(head, 2);

    while (temp != nullptr){
        cout << temp->val << ", " ;
        temp = temp->next;
    }

    return 0;

}