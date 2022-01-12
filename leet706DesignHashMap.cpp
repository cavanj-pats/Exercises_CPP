//leet 706 DesignHashMap
//leet706DesignHashMap.cpp

//1/11/2022

//leetcode accepted but it ran slowly  faster than only 11.66%

#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct dataPair {
    int key;
    int val;
};

class MyHashMap {
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        bool found = false;
        dataPair p;
        //if key exists update val to value
        if (vHashMap.size() == 0){
            p.key = key;
            p.val = value;
            vHashMap.push_back ( p );
        } else{
            for (int i = 0; i < vHashMap.size(); ++i){
                if (vHashMap[i].key == key) {
                    vHashMap[i].val = value;
                    found = true;
                   continue;
                }
            }
            if (!found){
                p.key = key;
                p.val = value;
                vHashMap.push_back(p);
            }
        }


        
    }
    
    int get(int key) {
        if (vHashMap.size() == 0 ) return -1;
        for(auto i: vHashMap){
            if (i.key == key) return i.val;
        }
        return -1;
    }
    
    void remove(int key) {
        for(int i = 0; i<vHashMap.size(); ++i){
            if(vHashMap[i].key == key) vHashMap.erase(vHashMap.begin()+i);
        }
    }

private:
    std::vector<dataPair> vHashMap;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */