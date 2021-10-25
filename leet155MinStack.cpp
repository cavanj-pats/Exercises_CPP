//leet 155.Min Stack    EASY

#include <iostream>
#include <vector>



using namespace std;

class MinStack {
public:
    MinStack() {
        size= 0;
        
    }
    
    vector<int> elements;
    int size;

    void push(int val) {
            elements.push_back(val);
            size++;
        
    }
    
    void pop() {
        elements.pop_back();
        size--;
        
    }
    
    int top() {
        return elements[size-1];
        
    }
    
    int getMin() {
        int x;
        for(int i=0; i<size; i++){
            if(i==0)
                x = elements[i];
            else
                if(elements[i]< x) x=elements[i];
        }
        return x;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){
    MinStack* obj = new MinStack();
    obj->push(4);
    obj->push(9);
    obj->push(87);
    cout << "Top: "<< obj->top() << endl;
    cout << "Min: "<< obj->getMin()<< endl;
    obj->pop();
    cout << "Top: "<< obj->top() << endl;
    cout << "Min: "<< obj->getMin()<< endl;

    


    delete obj;
    return 0;
}