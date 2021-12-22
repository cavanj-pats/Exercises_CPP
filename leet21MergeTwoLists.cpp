//21 leet merge two sorted lists

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode t1(0);
        ListNode* temp = &t1;
        
        /*
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        if (l1 == nullptr && l2!=nullptr) return l2;
        if (l1 != nullptr && l2 == nullptr) return l1;
        */

        while (l1 && l2){
            
            if (l1->val < l2->val){               
                temp->next = l1;
                l1 = l1->next;
                
            }else
            {
                temp->next = l2;
                l2=l2->next;
            }

            temp = temp->next;
        }

        temp->next = l1 ? l1 : l2;
        //l1 is nullptr then it will assign l2 to temp->next
        //l1 is not nullptr then l1 will be assigned to temp->next
        //if both lists are null then nullptr will be returned.
        //if one or the other is null,  the non null will be returned.
        //all by that one above line of code.
        
        return t1.next;   //t1 is a dummy but t1.next is the real head of the merged list.s
        
    }
};


int main(){
    ListNode* n1 = new ListNode;
    n1->val =1;
    n1->next = new ListNode(2);
    n1->next->next = new ListNode(4);

    ListNode* n2 = new ListNode(1);
    n2->next = new ListNode(3);
    n2->next->next = new ListNode(4);

    
    Solution sol;
    ListNode* ans = sol.mergeTwoLists(n1, n2);

    while (ans){
        cout << ans->val << ", ";
        ans = ans->next;

    }
    cout << endl;


    return 0;

    
}