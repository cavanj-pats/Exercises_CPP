//Min Heap Implementation of Priority Queue
//Priority is a queue  that gives priority to specific elements. In this case smaller "served" first.
//https://leetcode.com/discuss/general-discussion/1113631/important-concepts-problems-in-priority-queueheaps


#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
    private:
    vector<int> pq;

    public:
    PriorityQueue() {

    }

    bool isEmpty() {
        return pq.size() == 0;
    }

    int getSize() {
        return pq.size();
    }
    int getMin(){
        return pq[0];
    }

    void insert(int elem) {
        pq.push_back(elem);

        int childIndex = pq.size() - 1;

        while(childIndex > 0) {
            int parentIndex = (childIndex - 1)/2;
            if(pq[parentIndex] > pq[childIndex]) {
                swap(pq[parentIndex],pq[childIndex]);
            }
            else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        if(pq.size() == 0) {
            return -1;
        }
        
        int minVal = pq[0];
        int size = pq.size();
        swap(pq[0],pq[size - 1]);
        pq.pop_back();

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        int minIndex = 0;

        while(leftChildIndex < pq.size()) {
            if(pq[leftChildIndex] < pq[parentIndex]) {
                minIndex = leftChildIndex;
            }
            if(rightChildIndex < pq.size() && pq[rightChildIndex] < pq[minIndex]) {
                minIndex = rightChildIndex;
            }

            if(minIndex == parentIndex) {
                break;
            }

            swap(pq[minIndex], pq[parentIndex]);

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }

        return minVal;

    }

};


//driver code:
int main(){
    PriorityQueue p;
    vector<int> n = {4, 7, 3, 6};
    for(int i = 0; i<n.size(); ++i)
        p.insert(n[i]);

    std::cout<< "Size: "<<p.getSize() << endl;
    
    for(int i = 0; i<n.size(); ++i)
        std::cout << "Elements: "<< p.removeMin() << ", ";

    std::cout << endl;
    
    return 0; 
}