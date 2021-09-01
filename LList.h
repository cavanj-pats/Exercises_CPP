//linkedList.cpp

#include <iostream>

using namespace std;

template<class T> class LList;   //forward declare

template<class T>
    class LListNode{
        T data;
        LListNode<T>* next;
    public:
        LListNode(T newdata=T(), LListNode <T>* newNext = nullptr):
        data(newdata), next(newNext){}
        friend class LList<T>;
    };

template<class T>
    class LList{
        LListNode <T>* head;
        LListNode<T>* recursiveCopy(LListNode<T>* rhs);
    public:
        LList() :head(nullptr){}
        LList(const LList& rhs) :head(nullptr) {*this=rhs;}
        LList<T>& operator = (const LList<T>& rhs);
        ~LList(){clear();}
        void insertAtHead(T newdata);
        T removeFromHead();
        bool isEmpty() const {return head==nullptr;}
        void clear(); //while !isEmpty removeFromHead
        void insertAtPoint (LListNode<T>* ptr, T newdata);
        void insertAtEnd(T newdata);
        int size() const;

    };

template <class T>
    int LList<T>::size() const{
        int count =0;
        LListNode<T>* temp=head;
        while(temp!=nullptr){
            count++;
            temp = temp->next;
        }
        return count;
    }

template <class T>
    T LList<T>::removeFromHead(){
        //if(isEmpty())
        

        LListNode<T>* temp=head;
        head = head->next;
        return temp->data;
    }

template <class T>
    void LList<T>::insertAtHead(T newdata){
           //if the list is empty just insert
           //if the list is not empty 
           //
           LListNode<T>* temp = new LListNode<T>;

           temp->data = newdata;
           temp->next = head;
           head = temp;
    }

template <class T>
    void LList<T>::insertAtPoint (LListNode<T>* ptr, T newdata){
            //find node ptr
            //insert this node before it
            LListNode<T>* temp = new LListNode<T>;
            temp->data = newdata;
            LListNode<T>* point = new LListNode<T>;
            point = head;
            while(point->next!=ptr)
                point = point->next;
               
                temp->next = point->next;               
                point->next = temp;


    }


template <class T>
    void LList<T>::insertAtEnd(T newdata){
        if(isEmpty()){
            insertAtHead(newdata);
            return;
        }
        LListNode <T>* temp = new LListNode<T>;
        //LListNode <T> temp = (newdata);
        temp->data = newdata;
        LListNode <T>* end = head;
        //traverse the list starting at head and move until next is nullptr
        while(end->next!=nullptr)
            end = end->next;
        end->next = temp;
    }

    template <class T>
        void LList<T>::clear(){
        T tmp;
        while(!isEmpty()){
            tmp = removeFromHead();
        }

            
    }

    template <class T>
        LListNode<T>* LList <T>::recursiveCopy(LListNode<T>* rhs){
            if(rhs == nullptr)
                return nullptr;
            return new LListNode<T>(rhs->data, recursiveCopy(rhs->next));
        }

