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
        //similar to 83 delete duplicates
        //in this case remove all of teh elements with duplicates.
        ListNode* temp = head;
        bool headIsDup = false;
        
        if(head->val == head->next->val) headIsDup = true;
        
        while (temp->next){
           ListNode* t1 = temp->next;
           int iVal = t1->val;
           

           while (t1->next){
                
                if (t1->next->val != iVal) {                
                   if(temp->next != t1) temp->next = t1->next;  //this part resets the pointer
                    break;
                }
                else{
                    
                    temp->next = t1->next->next; //this part skips the equal nodes
                    t1 = t1->next;
                }
           }
            //
           // temp->next = t1;
            temp = temp->next;
            if (headIsDup){
                head = temp;
                headIsDup = false;
            }
           
           
            
           

           
        }
        return head;
    }
};
/*
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* t1 = head ;
        int val;

        if (!t1) return head;

        while (t1->next){
            if (t1->val == t1->next->val){
                t1->next = t1->next->next;  
                continue;
            }else
            {
              if(t1->next) t1 = t1->next;
            }
            
             
          

        }

        return head;
    }
};

*/

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