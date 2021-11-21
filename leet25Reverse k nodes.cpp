//25 Reverse Nodes in k-sized groups in singly linked list

#include <iostream>
#include <vector>

using namespace std;



//Definition for singly-linked list
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* rotateGroup (ListNode*, ListNode*, int);

  class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temp = new ListNode;
        ListNode* t;
        temp = head;    
        t = rotateGroup(head, temp, k);
        
        return t;
    }
};


ListNode* rotateGroup(ListNode* head, ListNode* temp, int k){
    
    vector<ListNode*> nodeStack;
    ListNode* t1 = new ListNode;
    ListNode* t2 = new ListNode;
    ListNode* t3 = new ListNode;
    bool isNextNull = false;
    int counter = 0;

    while (temp != nullptr){
        nodeStack.push_back(temp);
        counter++;
        if (counter%k == 0){    
            t1 = temp;   
            if(temp->next != nullptr){
            //if clearing stack
                nodeStack[0]->next = temp->next;  //when temp->next is nullptr it flushes list                                                
            }
            else{
                isNextNull = true;
            }
           
            //reverse pointers
            for (int i=nodeStack.size()-1; i>0; --i) nodeStack[i]->next = nodeStack[i-1];
                                   
            if (isNextNull)  nodeStack.front()->next = nullptr;  //front of stack is now the last node after reverse
             
            temp = nodeStack.front();   //now this is the last pointer in the reversed group
           
            if (counter == k){ 
                t2=nodeStack.back();  //this sets the new head of the reversed list.
                t3=nodeStack.front();
            }            
            if (counter > k ){
                    t3->next = nodeStack.back();//previous group last node point to this group first node
                    t3=nodeStack.front();  //reset t3 to be the last node of this group
            }      
            nodeStack.clear();            
        }
    temp = temp->next;
    }        
    return t2;
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
    head->next->next->next->next->next = new ListNode;
    head->next->next->next->next->next->val = 6;

    ListNode* temp = head;

    while (temp != nullptr){
        cout << temp->val << ", " ;
        temp = temp->next;
    }

    cout << endl<< "After two rotations: " << endl;

    temp = sol.reverseKGroup(head, 4);

    while (temp != nullptr){
        cout << temp->val << ", " ;
        temp = temp->next;
    }

    return 0;

}