//19 remove nth from end of list
//if there are 4 nodes and n =1.  the nth node is the last node
// if n = 2 then it is the next to last.

#include <iostream>

using namespace std;



//  Definition for singly-linked list.

struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* previous[30];
        int numNodes=0;
        
       

        while(temp->next !=nullptr){
            previous[numNodes] = temp;
            temp= temp->next;
            //previous = temp;
            numNodes++;
        }
        previous[numNodes]= temp;

        if (n==1 && numNodes==0) return nullptr;  //there was one node prior to removal
        if(n==numNodes+1) return head->next;    //head was removed
        if(n == 1 && numNodes==1){
            head->next = nullptr;    //temp currently pointing to the end pointer  remove last node
        }
        else{
            //remove numNodes - n + 1
            //numNodes-n ->next points to numNodes-n+1
            temp = head;  //reset to start of list
            while(temp->next != previous[numNodes-n+1]){
                temp = temp->next;
                
                
            }
            temp->next = temp->next->next;  //previous[numNodes-n+2];
        }

        return head;

    }
};


int main(){
    ListNode head(1);
    ListNode ptr2(2);
    ListNode ptr3(30);
    Solution sol;
    
    head.next = &ptr2;
    ptr2.next = &ptr3;

    ListNode *ans = sol.removeNthFromEnd(&head, 2);

    while(ans != nullptr){
        cout << ans->val << endl;
        ans = ans->next;
    
    }

    return 0;

}