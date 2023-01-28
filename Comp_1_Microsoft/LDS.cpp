// Fifth Question of Challange 1
// Question Name:- Largest Divisible Subset
// Leetcode #368

#include<bits/stdc++.h>
class Solution {
    vector<int> ans = {};
    int n;
    vector<int> temp;
    //  Simple recursion... gives TLE :)
    void solve(vector<int> &nums, int idx){
        if(idx == n){
            if(temp.size() > ans.size())
                ans = temp;
            return;
        }
        
        solve(nums, idx+1);
        if(temp.empty() || nums[idx] % temp.back() == 0){
            temp.push_back(nums[idx]);
            solve(nums, idx+1);
            temp.pop_back();
        }
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        // solve(nums, 0);
        // return ans;

        int maxi = 0, lastIdx = 0;
        //  dp to store max length from every index
        //  hash to store the prev index that is taken for every idx
        vector<int> dp(n, 1), hash(n);

        for(int i = 0; i < n; i++){
            hash[i] = i;

            for(int prev = 0; prev < i; prev++){
                if(nums[i] % nums[prev] == 0 && dp[i] < dp[prev]+1){
                    dp[i] = dp[prev]+1;
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIdx = i;
            }
        }
        //  deriving answer vector from computed values...
        vector<int> ans(maxi);
        for(int i = maxi-1; i >= 0; i--){
            ans[i] = nums[lastIdx];
            lastIdx = hash[lastIdx];
        }
        return ans;
    }
};