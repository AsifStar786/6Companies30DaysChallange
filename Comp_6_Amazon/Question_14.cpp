//  Question #14 of challenge #6(Amazon)
//  Name - Last moment before all ants fell down
//  LeetCode #1503


class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        
        for(auto it:left) ans = max(ans, it);
        for(auto it:right) ans = max(ans, n-it);
        return ans;
    }
};