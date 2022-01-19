//leet 142 Linked List II

//submitted and accepted.  was slow.  mine was faster than only 5%
//              1/18/2022

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int>  visited;
        unordered_map<ListNode* ,int>::iterator it;
        int pos=0;
        ListNode* temp = head;
        
        if (temp == nullptr) return nullptr;
        if (temp->next == nullptr) return nullptr;
        visited.emplace(temp,pos);
        
        while (temp != nullptr){
            temp = temp->next;
            ++pos;
            if(temp == nullptr) return nullptr;
            
            it = visited.find(temp);
            
            if (it == visited.end()){
                //not found
                visited.emplace(temp, pos);
            }else{
                
                break;
            }
            
           
            
        }
        
        return temp;
        
    }
};