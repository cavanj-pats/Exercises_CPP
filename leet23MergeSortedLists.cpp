//  Leet 23.MergeSortedLists
//leet23MergeSortedLists.cpp
#include <iostream>
#include <vector>

using namespace std;


void selection_sort(vector<int> &arr, int elements);
void swap(int *xp, int *yp);


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
        
    }

     ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        int i=0;
        ListNode* merged = new ListNode;
        ListNode* temp = new ListNode;
        temp = merged;
        if(lists.size() == 0) return nullptr;
        if(lists[0]==nullptr) return nullptr;

        for(auto l: lists){
            while (l !=nullptr){
                arr.push_back(l->val);
                i++;
               
                l = l->next;
            }
        }
        if(i==0) return nullptr;
        
        vector<int> &a = arr;
        selection_sort(a,i);
        temp = merged;
        
        
        for(int j=0; j<i; j++){
            
            temp->val = a[j];    
            if(j!=i-1) {
                temp->next = new ListNode;        
           
                temp=temp->next;
            }
                        
        }

        return merged;

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

void selection_sort(vector<int> &  arr, int elements){
    int temp;
    int idx;

    for (int i=0;i<elements;i++){
        temp = arr[i];
        idx = i;
        for (int j=i+1; j<elements;j++){
            if(arr[j] < temp){
                temp = arr[j];
                idx = j;
            }
        }
        //swap item at [i] with temp
        if (idx !=i)
            swap(arr[i], arr[idx]);
    }
}


void swap(int *xp, int *yp){
    int temp;
    temp = *xp;
    *xp = *yp;
    *yp = temp;
}



int main(){
    ListNode* n = new ListNode;
    ListNode* n1 = new ListNode;
    ListNode* node = new ListNode;
    ListNode* swap = new ListNode;
    ListNode* n2 = new ListNode;
    ListNode* n3 = new ListNode;
    ListNode* n4 = new ListNode;
    ListNode* n5 = new  ListNode;
    ListNode* n6 = new ListNode;
    ListNode* temp = new ListNode;

    vector<ListNode*> list;

    Solution sol ;



    n->val = 1;
    node->val = 4;
    n1->val = 5;

    n2->val = 1;
    n3->val = 3;
    n4->val = 4;
    
    n->next = node;
    n->next->next = n1;

    n2->next = n3;
    n2->next->next= n4;

    n5->val = 2;
    n6->val = 6;
    n5->next = n6;
    
    
    list.push_back(n);
    list.push_back(n2);
    list.push_back(n5);

    for(auto l: list){
        while(l !=nullptr){
            cout << l->val << ", ";
            l=l->next;
        }
    }
    cout << endl;


    temp = sol.mergeKLists(list);

    while (temp != nullptr){
        cout << temp->val << ", ";
        temp = temp->next;
    }
    cout << endl;


    /* Solution sol;
    swap = sol.swapPairs(n);
    

    while (swap != nullptr){
        cout << swap->val << ", ";
        swap = swap->next;
    }
    cout << endl; */


    delete n;
    delete n2;
    delete n3;
    delete n4;
    delete temp;
    delete node;
    delete swap;

    return 0;

}