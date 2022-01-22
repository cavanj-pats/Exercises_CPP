//leet 82 remove element from list

/*
Runtime: 18 ms, faster than 13.52% of C++ online submissions for Remove Duplicates 
from Sorted List II.
Memory Usage: 11.1 MB, less than 58.25% of C++ online submissions for Remove Duplicates 
from Sorted List II.
*/

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
        
        ListNode* temp = head;//if head is part of a duplicate we need to reassign head ptr
        ListNode* t1 = temp;
        ListNode* firstDup; 
        ListNode* lastDup;
        bool moveHead = false;

        if (head == nullptr || head->next == nullptr) return head;

            while (temp->next){
                if (temp->val == temp->next->val){
                    firstDup = temp;
                    lastDup = temp;
                    do{
                        lastDup = lastDup->next;
                    }while(lastDup && lastDup->val == firstDup->val);
                    if(temp == head){
                        head = lastDup;
                        temp = lastDup;
                        moveHead = true;
                    }
                    else{
                        temp = t1;
                        temp->next = lastDup;
                        
                    }
                }
                if (!moveHead){
                    t1 = temp;
                    temp = temp->next;
                }
                else{
                    moveHead = false;
                }
                if (temp == nullptr) break;
            }

            return head;
            
        }
    };
     
           
           
        /*   
           
           
           if (t2 == nullptr) break;

            if (temp->val == t1->val && temp == head){
                t1 = temp;
                t2 = temp->next;
            }
            if(t1->val == t2->val){
                while (t2) {
                    if (t1->val == t2->val){
                        if (t2->next == nullptr){
                            t2 = nullptr;
                            break;
                        }
                        t2=t2->next;
                    }else{
                        if (t1 == head){
                            head = t2;
                        }else 
                        {
                            temp->next = t2;
                        }
                       
                        break;
                    }
                    
                }
 
             
            }else { 
                if (temp->next == nullptr) break;
                temp = temp->next;  //move one node over
            }
            
            
        }

        return head;  


    }
       
        
        
};
*/


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
    head->next->val = 1;
    head->next->next = new ListNode  ;
    head->next->next->val = 2;
    head->next->next->next = new ListNode ;
    head->next->next->next->val = 2;
    head->next->next->next->next = new ListNode ;
    head->next->next->next->next->val = 5 ;
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