//2.Add two numbers
//eliminating the last "list populating loop" increased speed and reduced memory reqmts

#include<iostream>
#include<vector>
#include<cmath>
#include<string>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* temp1 = l1;
        ListNode* temp2=l2;
        
        int i;
        int j=0;
        
        vector<int> ans1;
        vector<int> ans2;
        vector<int> ans3;
        
        
        while(temp1 !=nullptr){
            ans1.push_back(temp1->val);
            temp1=temp1->next;
        }    
        while(temp2 !=nullptr){
            ans2.push_back(temp2->val);
            temp2=temp2->next;
        }   
        
        //ans3 = ans1;
        if(ans1.size()>ans2.size()){
            ans3 = ans1;
            for(int x=0; x<ans2.size();x++){
                ans3[x]+=ans2[x];
            }
        }
        else {
            ans3 = ans2;
            for(int x=0; x<ans1.size(); x++){
                ans3[x]+=ans1[x];
            }
        }

        
        ListNode* temp = head;

        
        for(int j=0; j<ans3.size(); j++){
            if(j==ans3.size()-1){
                if(ans3[j]>9){
                    ans3[j] = ans3[j]-10;//highest it can be is 18
                    ans3.push_back(1);
                    
                }
            }else{
                if(ans3[j]>9){
                    ans3[j] = ans3[j]-10;
                    ans3[j+1] = ans3[j+1]+1;
                }
            }
            temp->val=ans3[j];
            if(j<ans3.size()-1){
                temp->next = new ListNode();
                temp = temp->next;
            }
            if(j==ans3.size()-1) temp->next = nullptr ;
        }
        
        
        //string num;
        //num = nodeValue(l1) + nodeValue(l2);
        //num = to_string(value);
        

        /*
        
        i=ans3.size()-1;
        ListNode* temp = head;

        for(int k=0; k<ans3.size(); k++){
            temp->val=ans3[k];
            if(k<i) {
                temp->next = new ListNode();
                temp = temp->next;
            }
            if(k==i) temp->next = nullptr;
            

        }

        */

        /* while(temp !=nullptr){
            temp->val=ans3[i];
            if(i>0) temp->next = new ListNode();   
            if(i==0) temp->next = nullptr;
           temp = temp->next;
            i--;
            
        } */
        

        return head;
    }
};
// unsigned long long int nodeValue(ListNode*);

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* head = new ListNode();
//         int j;
//         vector<int> ans;
//         string num;
//         unsigned long long int value = nodeValue(l1) + nodeValue(l2);
//         num = to_string(value);
//         j=num.size()-1;
//         ListNode* temp = head;

//         while(temp !=nullptr){
//             temp->val=num[j]-48;
//             if(j>0) temp->next = new ListNode();   
//             if(j==0) temp->next = nullptr;
//            temp = temp->next;
//             j--;
            
//         }
        

//         return head;
//     }
// };

// unsigned long long int nodeValue(ListNode* node){
//     ListNode* temp = node;
//     //string str="";
//     vector<unsigned long long int> val;
//     unsigned long long int result=0;
//     int i=0;

//     while(temp !=nullptr){
//         val.push_back(temp->val);
//         temp=temp->next;
//     }
    
//     i = val.size();
//     for(long long int j=0; j<val.size(); j++){
//         result+= val[j]*pow(10,j);
//     }

//     /*
//     while(val.size()>0){
//         result+=val.back()*pow(10,i);
//         val.pop_back();
//         i++;
//     }
//     */
//     return result;
// }



int main(){
    ListNode* node1 = new ListNode(9);
    ListNode* node2 = new ListNode(9);
    ListNode* node3 = new ListNode();
    Solution sol;

    node1->next= new ListNode(9);
    node1->next->next = new ListNode(9);
    node1->next->next->next = new ListNode(9);
    //node1->val = 3;
    //node2->val = 5;
    node2->next = new ListNode(9);
    node2->next->next = new ListNode(9);

    node3 = sol.addTwoNumbers(node1, node2);
    
    cout << node3->val << ", ";
    cout << node3->next->val << ", ";
    cout << node3->next->next->val << endl;


    return 0;

    //cout << 

}