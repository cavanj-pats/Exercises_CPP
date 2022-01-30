/*    leet 841 Keys and Rooms
***I used leetcode code.  I don't understand this

Success
Details 
Runtime: 13 ms, faster than 41.79% of C++ online submissions for Keys and Rooms.
Memory Usage: 10.3 MB, less than 93.56% of C++ online submissions for Keys and Rooms.
*/
class Solution {
public:

    void dfs(vector<vector<int>> &graph, int s, vector<bool> &vis){
        vis[s] = true;
        for(int i = 0; i < graph[s].size(); i++){
            if(!vis[graph[s][i]]){
                dfs(graph, graph[s][i], vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int i, n=rooms.size();
        vector<bool> vis(n, false);
        dfs(rooms, 0, vis);
        for(i = 0; i < n; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};