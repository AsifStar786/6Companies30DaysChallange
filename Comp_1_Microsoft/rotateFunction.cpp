// Fourth Question of Challange 1
// Question Name:-
// Rotate Function
// Leetcode #396

#include<bits/stdc++.h>
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0, curr = 0, n = nums.size();
        // calculate sum and F(0) as curr
        for(int i = 0; i < n; i++){
            sum += nums[i];
            curr += nums[i]*i;
        }
        //  init ans = curr and last index as idx = n-1
        int ans = curr, idx = n-1;

        // calculate F(1)....F(n-1)
        while(idx > 0){
            // using prev value...
            int val = curr + sum - nums[idx--]*n;
            ans = max(ans, val);
            curr = val;
        }

        return ans;
    }
};