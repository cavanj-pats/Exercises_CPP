//203 leet remove list elements

#include <iostream>


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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode t1(0);
        ListNode* temp = &t1;
        ListNode* t2 = head;

        while (t2){
            if(t2->val!=val){
                temp->next = t2;
                t2 = t2->next;
                temp = temp->next;
            }else {
                t2 = t2->next;
                temp->next = t2;
                //temp = temp->next;
            }
        }

        return t1.next;

    }
};


int main(){
    ListNode* n1 = new ListNode;
    n1->val =1;
    n1->next = new ListNode(2);
    n1->next->next = new ListNode(6);
    n1->next->next->next = new ListNode(3);
    n1->next->next->next->next = new ListNode(4);
    n1->next->next->next->next->next = new ListNode(5);
    n1->next->next->next->next->next->next = new ListNode(6);

    /*
    ListNode* n2 = new ListNode(1);
    n2->next = new ListNode(3);
    n2->next->next = new ListNode(4);
    */

    Solution sol;
    ListNode* ans = sol.removeElements(n1, 6);

    while (ans){
        cout << ans->val << ", ";
        ans = ans->next;

    }
    cout << endl;


    return 0;

    
}