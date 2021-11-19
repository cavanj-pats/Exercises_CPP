//leet61 Rotate Right
// rotate a linked list to the right k times
//recursive solution ran slower than iterative solution

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

ListNode* oneRight(ListNode*, ListNode*,  int , int);

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
       // ListNode* newHead = new ListNode;
        int counter=0;
        if (head == nullptr || head->next == nullptr) return head;
        if (k <= 0) return head;
        
         return oneRight(head, temp, counter, k);
         
    }
};

//the below code woudl not work. 
//each run of the recursion renews the snapshot of head and temp and newHead
//i did get one rotation working but I think that was when the node assignments and swapping were in teh while loop.
ListNode* oneRight(ListNode* head, ListNode* temp, int counter, int k){
   //counter = 0;
   
    if (temp->next == nullptr ){
       ListNode* newHead = new ListNode;
       NODECOUNT = counter + 1;
       if (k>NODECOUNT) k = k%NODECOUNT;
       if (k != NODECOUNT && k!=0) temp->next = head;  //could create a looping list where tail points to head.
       newHead = head; 
       
       return newHead;
         
    }     
    ListNode* t = new ListNode;       
    t = oneRight(head, temp->next,  counter+1, k);
    if(k ==  NODECOUNT || k==0) {
        return head;
        }
    else{
        if (k>NODECOUNT) k = k%NODECOUNT;  //the previous calculation occured in the recursion at the tail.
                                        //the above occurs at the rotation point
                                        //NODECOUNT is not known until the tail is reached.

        if (counter ==NODECOUNT- k - 1){
            t = temp->next;
            temp->next = nullptr;
            return t;    
        }
    }
                 
    return t;
    

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

    temp = sol.rotateRight(head, 100001);

    while (temp != nullptr){
        cout << temp->val << ", " ;
        temp = temp->next;
    }

    return 0;

}