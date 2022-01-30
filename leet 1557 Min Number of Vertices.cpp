
/*

****LEETCODE CODE TO BE STUDIED

1557. Minimum Number of Vertices to Reach All Nodes
Medium

1169

59

Add to List

Share
Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.


Success
Details 
Runtime: 788 ms, faster than 5.04% of C++ online submissions for Minimum Number of Vertices to Reach All Nodes.
Memory Usage: 106.8 MB, less than 29.93% of C++ online submissions for Minimum Number of Vertices to Reach All Nodes.
Next challenges:
 
 */


class Solution {
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int> res, in(n);
    for(auto edge: edges)
      in[edge[1]]++;
    for(int i=0; i!=n; ++i)
      if(in[i]==0) res.push_back(i);
    return res;
  }
};