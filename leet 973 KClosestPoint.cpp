//leet 973 K closes to origin

/*
Success
Details 
Runtime: 290 ms, faster than 34.56% of C++ online submissions for K Closest Points to Origin.
Memory Usage: 71.5 MB, less than 22.63% of C++ online submissions for K Closest Points to Origin.

****
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


class Point{
    public:
        int x;
        int y;
        int distance;
        Point(int a, int b){
            x = a;
            y = b;
            distance = ((x*x) + (y*y));
        }

        

        bool operator <(const Point& a){
            if (distance < a.distance ) return true;

            return false;
        }
};

bool cmp(Point a, Point b){
    return a < b;
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<Point> distances;
        vector<int> pt = {0,0};
        vector<vector<int>> result;


        for(auto p:points){
            Point myPoint(p[0],p[1]);
            distances.push_back(myPoint);
        }   

        sort(distances.begin(), distances.end(),cmp);

        for (int i = 0; i<k; ++i){
            pt[0]= distances[i].x;
            pt[1]= distances[i].y;
            result.push_back(pt);
        }   


        return result;
    }
};


int main(){
    Solution sol;
    vector<vector<int> > n = {{3,3},{5,-1},{-2,4}} ;
    int k = 2;

    vector<vector<int>> result = sol.kClosest(n,k);
    cout << k << " Closes points to origin:"<< endl;
    for (auto r:result){
        cout << r[0] << ", " << r[1] << "   ,";
    }

    cout << endl;
    return 0;

}