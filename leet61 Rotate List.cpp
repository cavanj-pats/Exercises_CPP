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

int NODECOUNT = 0;

void oneRight(ListNode*, ListNode*, ListNode*, int , int);

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* newHead = new ListNode;
        int counter=0;
        if (head == nullptr || head->next == nullptr) return head;
        if (k <= 0) return head;
        
        //oneRight(head, temp, newHead, counter, k);
         //counter = 0;
        while (temp->next !=nullptr){
            counter++;
            
            temp = temp->next;
        }

        
        NODECOUNT = counter+1;  //length of list
        if (k == NODECOUNT) return head;

        if (k>NODECOUNT)  k=k%NODECOUNT;  //i think this will recalculate k in terms of list position for rotation
        
        //the below line is a little dangerous is it could create a circular list.
        temp->next = head;   //since we are swapping at least one node this has to point to the old head
        temp = head;
        for (int i=1; i<NODECOUNT -k; ++i){
            temp = temp->next;

        }
        //should be at teh point of rotation
        newHead = temp->next;
        temp->next = nullptr;

        return newHead;

    }
};

//the below code woudl not work. 
//each run of the recursion renews the snapshot of head and temp and newHead
//i did get one rotation working but I think that was when the node assignments and swapping were in teh while loop.
void oneRight(ListNode* head, ListNode* temp, ListNode* newHead, int counter, int k){
   counter = 0;
   while (temp->next !=nullptr){
       counter++;
       temp = temp->next;
   }
   temp->next = head;   //since we are swapping at least one node this has to point to the old head

   NODECOUNT = counter+1;  //length of list
    
    if (k>NODECOUNT)  k=k%NODECOUNT;  //i think this will recalculate k in terms of list position for rotation
    
    temp = head;
    for (int i=0; i<NODECOUNT-k; ++i){
        temp = temp->next;

    }
     //should be at teh point of rotation
     newHead = temp->next;
     temp->next = nullptr;
     //head = newHead;   //funny head returns to nullptr in calling function

    return ;


   
   
    /*   
    if (temp->next->next == nullptr ){
       NODECOUNT = counter + 2;
       
       newHead = head; 
       return;
         
    }     
           
    oneRight(head, temp->next, newHead, counter+1, k);
    

    if ((NODECOUNT-counter+1) >= k){
       // ListNode* t = new ListNode;
        newHead->val = temp->next->next->val;
        newHead->next = head;
        temp->next = nullptr;
        head = newHead;
        //return;    
    }
                 
    return;
    */

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

    temp = sol.rotateRight(head, 3);

    while (temp != nullptr){
        cout << temp->val << ", " ;
        temp = temp->next;
    }

    return 0;

}