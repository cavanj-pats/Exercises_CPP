//leet232 Implement queue using stack



#include <iostream>
#include <vector>

using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    
    vector<int> data;

    void push(int x) {
        data.push_back(x);
    }
    
    int pop() {
        int d = data.front();
        data.erase(data.begin());
        return d;
    }

    int peek() {
        return data.front();
    }
    
    bool empty() {
        if (data.size() == 0) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */