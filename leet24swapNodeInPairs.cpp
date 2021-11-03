//  Leet 24.SwapNodesInPairs
//leet24swapNodeInPairs.cpp
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
    ListNode* swapPairs(ListNode* head) {

       return spHelper(head);
       /*
       
        //traverse the list and swap two adjecent nodes.
        ListNode* temp1 = new ListNode;
        ListNode* temp2 = new ListNode;
        ListNode* temp3 = new ListNode;
        ListNode* temp4 = new ListNode;

        int i=0;        

        if(head == nullptr) return head;   //null 
        if(head->next == nullptr) return head;  //one node
        //the first swap needs to involve head so that head will become what is now the second NODE
        temp1 = head;
        while(temp1!=nullptr){
            i++;
            temp1=temp1->next;
        }



        temp1 = head;  //node 1, node 1 points to node 2
        temp2 = head->next;  //node 2,  node 2 points to node 3
        temp1->next = temp2->next;
        head = temp2;
        head->next = temp1;

        if(i<4) return head;

       
        temp1 = head->next;  //this is node 2
        temp2 = head->next->next; 
        temp3 = head->next->next->next; //this is node 3  new node 4
        temp4 = head->next->next->next->next;
                              //temp2->next is node 4
                              //swap node 3 with 4
        //node   node->next   node->next->next   node->next->next->next
        //node   node->next->next   node->next   node->next->next->next

        while(temp1->next->next !=nullptr){
            //swap 

            temp3->next = temp2;
            temp2->next = temp4;
            temp1->next = temp3;
            temp3->next = temp2;
          //  temp1->next->next->next = temp3->next; 
           
           
           //if(temp1->next->next->next->next == nullptr) i=4;
           if(temp1->next->next->next == nullptr) return head;  //there are no more nodes to swap
            if(temp1->next->next->next->next == nullptr) return head; //there is only one more node
            
           // if(temp1->next->next == nullptr) return head;  //there is only one more node to swap
          
               temp1 = temp1->next->next;
               temp2 = temp1->next;
               temp3 = temp2->next;
               temp4 = temp3->next;
           
           
           
               
        }
        
        return head;
    */
        
    }

    private:
    ListNode* spHelper(ListNode* head){
        ListNode* temp = new ListNode;
        ListNode* temp1 = new ListNode;

        if(head == nullptr) return head;   //null 
        if(head->next == nullptr) return head;  //one node
               
        temp = head->next;
        head->next = head->next->next;
        temp->next = head;

        head = temp;
        head->next->next = spHelper(head->next->next);

       
        return head;

    }
};


int main(){
    ListNode* n = new ListNode;
    ListNode* node = new ListNode;
    ListNode* swap = new ListNode;
    ListNode* n2 = new ListNode;
    ListNode* n3 = new ListNode;
    ListNode* n4 = new ListNode;
    ListNode* temp = new ListNode;


    n->val = 1;
    node->val = 2;
    n2->val = 6;
    n3->val = 9;
    n4->val = 3;
    
    n->next = node;
    n->next->next = n2;
    n->next->next->next = n3;
    n->next->next->next->next = n4;
    
    temp = n;
    
    while (temp != nullptr){
        cout << temp->val << ", ";
        temp = temp->next;
    }
    cout << endl;

    Solution sol;
    swap = sol.swapPairs(n);
    

    while (swap != nullptr){
        cout << swap->val << ", ";
        swap = swap->next;
    }
    cout << endl;


    delete n;
    delete n2;
    delete n3;
    delete n4;
    delete temp;
    delete node;
    delete swap;

    return 0;

}