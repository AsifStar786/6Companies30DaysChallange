//  Question #6 of challenge #6(Amazon)
//  Name - Maximum Subarray min-Product
//  LeetCode #1856

class Solution {
public:
    int maxSumMinProduct(vector<int>& n) {
        long res = 0;
        vector<long> dp(n.size() + 1), st;

        for (int i = 0; i < n.size(); ++i)
        dp[i + 1] = dp[i] + n[i];
        for (int i = 0; i <= n.size(); ++i) {
            while (st.size() && (i == n.size() || n[st.back()] > n[i])) {
                int j = st.back();
                st.pop_back();
                res = max(res, n[j] * (dp[i] - dp[st.empty() ? 0 : st.back() + 1]));
            }
            st.push_back(i);
        }
        return res % 1000000007;
    }
};