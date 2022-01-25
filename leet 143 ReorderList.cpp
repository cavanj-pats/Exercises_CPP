//leet 143 reorder list

/*
Runtime: 66 ms, faster than 19.19% of C++ online submissions for Reorder List.
Memory Usage: 18.4 MB, less than 34.29% of C++ online submissions for Reorder List.
*/



#include <stack>
#include <iostream>




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
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        ListNode* fromTail;
        std::stack <ListNode*> nodeStack;
        
        //traverse list and load the stack

        while (temp){
            nodeStack.push(temp);
            temp = temp->next;
        }

        temp = head;
        int i = 0;
        int j = nodeStack.size();

        if (j == 2){
           /*  ListNode* t1 = nodeStack.top();
            nodeStack.pop();
            t1->next = nodeStack.top();
            temp = t1;
            
            //temp->next = nodeStack.top();
            temp->next->next = nullptr; */
        } else{

            while (( nodeStack.size() )> j/2-1 ){
                fromTail = nodeStack.top();
                nodeStack.pop();
                fromTail->next = temp->next;
                temp->next = fromTail;
                temp = temp->next->next;
                
                if(temp == nodeStack.top()){
                    //this is the new tail of an odd number of nodes
                    temp->next = nullptr;
                    break;
                }else if( temp->next == nodeStack.top()){
                    temp->next->next = nullptr;
                    break;
                }

            }
        }
         
               
        
    }
};


int main(){
    Solution Sol;
    
    ListNode*  headA = new ListNode(1);
    headA->next = new ListNode(2);
   // headA->next->next = new ListNode(3);
    //headA->next->next->next = new ListNode(4);
    //headA->next->next->next->next = new ListNode(5);
    //headA->next->next->next->next->next = new ListNode(6);

    Sol.reorderList(headA);

    while (headA){
        std::cout << headA->val << ", ";
        headA = headA->next;
    }



    return 0;

}