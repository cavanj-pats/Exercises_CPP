//leet 83 remove element from list


#include <iostream>


using namespace std;


 //* Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* t1 = head ;
        int val;

        while (t1->next){
            if (t1->val == t1->next->val)
                t1->next = t1->next->next;
             
          if(t1->next) t1 = t1->next;

        }

        return head;
    }
};


int main(){
    Solution sol;
    ListNode* head = new ListNode ;
    head->val = 1;
    head->next = new ListNode ;
    head->next->val = 2;
    head->next->next = new ListNode  ;
    head->next->next->val = 2;
    head->next->next->next = new ListNode ;
    head->next->next->next->val = 4;
    head->next->next->next->next = new ListNode ;
    head->next->next->next->next->val = 6 ;
    head->next->next->next->next->next = new ListNode;
    head->next->next->next->next->next->val = 6;

    ListNode* temp = head;

    while (temp != nullptr){
         temp->next == nullptr ? cout << temp->val :cout << temp->val << ", " ;
        temp = temp->next;
    }

    cout << endl<< "After duplicate removal: " << endl;

    temp = sol.deleteDuplicates(head);

    while (temp != nullptr){
        temp->next == nullptr ? cout << temp->val :cout << temp->val << ", " ;
        temp = temp->next;
    }
    cout << endl;



    return 0;
}