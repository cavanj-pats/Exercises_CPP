//1491 leet
//this code worked  about better than 40% so it could be better faster and less memory

//ignore min and max salary

class Solution {
public:
    double average(vector<int>& salary) {
        double ans = 0.0;
        sort(salary.begin(), salary.end());
        for (int i = 1; i< salary.size()-1; ++i)
            ans += (double) salary[i];
        
        return ans / (salary.size()-2);
    }
};