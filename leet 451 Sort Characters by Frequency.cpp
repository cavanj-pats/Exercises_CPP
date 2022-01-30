//leet 451 Sort Characters By Frequency 

/*
Success
Details 
Runtime: 12 ms, faster than 82.19% of C++ online submissions for Sort Characters By Frequency.
Memory Usage: 8.5 MB, less than 43.12% of C++ online submissions for Sort Characters By Frequency.
*/


template <typename T1, typename T2>
struct gt_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second > b.second;
    }
};


class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> cMap;
      
        string result = "";
        int i = 0;
        int j = s.size()-1;
        bool even = s.size()%2 ==0 ? true : false ;
        while (i<j){
            cMap[s[i]]++;
            cMap[s[j]]++;
            ++i;
            --j;
        }
        if (!even) cMap[s[i]]++;

        vector<pair<char, int> > mapcopy(cMap.begin(), cMap.end());
        sort(mapcopy.begin(), mapcopy.end(), gt_second<char, int>());
        
        int count = 0;
        for (auto m : mapcopy){
            for(int x=0; x<m.second; ++x)
                result += m.first;
            
        }
        
        return result;
    }
};