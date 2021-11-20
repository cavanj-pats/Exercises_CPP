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
            t1 = temp;    //even if this is nullptr should be ok
            if(temp->next != nullptr){
            //if clearing stack
                nodeStack[0]->next = temp->next;  //when temp->next is nullptr it flushes list
            }
            else{
                isNextNull = true;
            }
           // nodeStack[counter-k]->next = temp->next;   //the old head now points to the next group
          // temp->next = nodeStack.back()->next;    //this should position temp at the last node of the reversed group
            

          //********************************************
           //if clearing stack
           for (int i=nodeStack.size()-1; i>0; --i){
               nodeStack[i]->next = nodeStack[i-1];
           }
            
           
            if (isNextNull){           
                nodeStack.front()->next = nullptr;
                //temp = t1;
            }

             temp = nodeStack.front();


           //if NOT clearing stack
            // for(int i = counter-1; i>counter-k; --i){
            //     nodeStack[i]->next = nodeStack[i-1];
            // }
            //******************************************
           
           if (counter == k){ 
               t2=nodeStack.back();
               t3=nodeStack.front();
               
           }
           
           if (counter > k ){
                t3->next = nodeStack.back();
                t3=nodeStack.front();

           }      
           // t1->next = nodeStack.back();
           
           
            
            
            
            //for(int i = nodeStack.size()-1; i>0 ; --i){
            // for(int i = counter-1; i>counter-k; --i){
            //     nodeStack[i]->next = nodeStack[i-1];
            // }

            
            // nodeStack[counter-k]->next = temp->next;   //the old head now points to the next group
           // nodeStack.pop_back();
           //t1=nodeStack.back();
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

    temp = sol.reverseKGroup(head, 6);

    while (temp != nullptr){
        cout << temp->val << ", " ;
        temp = temp->next;
    }

    return 0;

}