//  Question #6 of challenge #2(Goldman Sachs)
//  Name - Minimum consecutive cards to pick.
//  LeetCode #2260

#include<bits/stdc++.h>
class Solution {
public:
    int minimumCardPickup(vector<int>& c) {
        int ans = INT_MAX;
        unordered_map<int, int> mp;

        for(int i = 0; i < c.size(); i++){
            if(mp.find(c[i]) == mp.end()){
                mp[c[i]] = i;
            }
            else{
                int d = i - mp[c[i]] + 1;
                mp[c[i]] = i;
                ans = min(ans, d);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};