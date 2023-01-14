//  Question #10 of challenge #2(Goldman Sachs)
//  Name - number of people with secret
//  LeetCode #2327

#include<bits/stdc++.h>
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long int> v(n+1, 0);
        v[1] = 1;
        long long int ans = 0, mod = 1e9+7;

        for(int i = 1; i <= n; i++){
            for(int j = i+delay; j < i+forget; j++){
                if(j <= n) v[j] = (v[i] + v[j])%mod;
            }
        }

        while(forget--)
            ans = (ans + v[n--])%mod;
        return ans;
    }
};