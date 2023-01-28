//  Question #11 of challenge #6(Amazon)
//  Name - Number of ways to reach a position
//  LeetCode #2400


class Solution{
    long solve(int start, int end, int k, vector<vector<long>> &dp){
        if(!k) return start == end;

        if(dp[start][k] != -1) return dp[start][k];
        long ans = solve(start-1, end, k-1, dp);
        ans = (ans + solve(start+1, end, k-1, dp)) % 1000000007;
        return dp[start][k] = ans;
    }
public:
    int numberOfWays(int start, int end, int k){
        if(start > end)
            swap(start, end);
        long diff = start - k;
        start -= diff;
        end -= diff;
        vector<vector<long>> dp(end+k+1, vector<long> (k+1, -1));
        return solve(start, end, k, dp);
    }
};