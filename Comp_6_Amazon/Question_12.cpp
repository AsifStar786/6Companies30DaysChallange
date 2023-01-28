//  Question #12 of challenge #6(Amazon)
//  Name - Maximum length of matching subarray
//  LeetCode #718

class Solution{
    int ans = 0;
    int solve(vector<int> &a, vector<int> &b, int i, int j, vector<vector<int>> &dp){
        if(i == a.size() || j == b.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        max(ans, solve(a, b, i+1, j, dp));
        max(ans, solve(a, b, i, j+1, dp));
        dp[i][j] = 0;
        if(a[i] == b[j]){
            int curr = solve(a, b, i+1, j+1, dp);
            ans = max(ans, curr+1);
            dp[i][j] = curr+1;
        }
        return dp[i][j];
    }
public:
    int findLength(vector<int>& a, vector<int>& b){
        int m = a.size(), n = b.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));

        solve(a, b, 0, 0, dp);
        return ans;
    }
};