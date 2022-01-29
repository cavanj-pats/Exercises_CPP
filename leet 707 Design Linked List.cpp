//Linked List Design

#include <iostream>


//* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class MyLinkedList {
public:
    int size=0;
    ListNode* head = new ListNode;
    MyLinkedList() {
        
    }
    
    int get(int index) {
        if (index >= size) return -1;
        if (index == 0) return head->val;
        ListNode* temp = head;
        
        for (int i=0; i < index; ++i)temp = temp->next;
        
        return temp->val;
    }
    
    void addAtHead(int val) {
        if (size ==0){
            head = new ListNode(val);
        }
        else{
            ListNode* t = new ListNode(val);
            t->next = head;
            head = t;
        }
        ++size;
        
    }
    
    void addAtTail(int val) {
        ListNode* t = new ListNode(val);
        ListNode* temp = head;
        while (temp->next){
            temp = temp->next;
        }
        temp->next = t;
        ++size;
        
    }
    
    void addAtIndex(int index, int val) {
        if (index > size-1) return;
        ListNode* t = new ListNode(val);
        ListNode* temp = head;
        ListNode* previous = head;
        
        for(int i=0; i< index; ++i){
            previous = temp;
            temp = temp->next;
            
        }
        
        t->next = temp;  //new node points to insertion point
       
        if (index ==0 ) {
            head = t;
        }
        else{
            previous->next = t;  //temp become t but previous node is not pointing to t
        }
        
        ++size;
    }
    
    void deleteAtIndex(int index) {
        ListNode* t = head;
        ListNode* temp = head;
        if (index <0) return;
        if (index > size-1) return;
        for (int i = 0; i< index; ++i){
            temp=t;
            t = t->next;
            
        }
        
        temp->next = t->next;
        --size;
    }

    
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


int main(){
    MyLinkedList* obj = new MyLinkedList();
    
    obj->addAtHead(7);
    obj->addAtHead(2);
    obj->addAtHead(1);
    obj->addAtIndex(0,3);
    obj->deleteAtIndex(2);
    obj->addAtHead(6);
    obj->addAtTail(4);
    std::cout << obj->get(0) << std::endl;
    
   // obj->addAtIndex(1,2);
    

    std::cout << "Size: " << obj->size << std::endl;
    for(int i = 0; i<obj->size; ++i){
        std::cout << obj->get(i) << ", ";
    }
    std::cout << std::endl;

    obj->deleteAtIndex(1);

    std::cout << "Size after delete: " << obj->size << std::endl;
    for(int i = 0; i<obj->size; ++i){
        std::cout << obj->get(i) << ", ";
    }
    std::cout << std::endl;

    return 0;
}