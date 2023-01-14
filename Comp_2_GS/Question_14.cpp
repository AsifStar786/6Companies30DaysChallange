//  Question #14 of challenge #2(Goldman Sachs)
//  Name - nice pairs in an array
//  LeetCode #1814

#include<bits/stdc++.h>
class Solution {
    // map<vector<int>, int> map;
    // void decode(int n){
    //     int prev = n%10;
    //     n /= 10;
    //     if(!n){
    //         map[{0}]++;
    //         return;
    //     }
    //     vector<int> v;
    //     bool flag = 0;
    //     while(n){
    //         int temp = n%10;
    //         n /= 10;
    //         v.push_back(temp-prev);
    //         if(temp - prev != 0) flag = 1;
    //         prev = temp;
    //     }
    //     if(flag)
    //         map[v]++;
    //     else map[{0}]++;
    // }
public:
    // int countNicePairs(vector<int>& nums) {
    //     for(auto it:nums) decode(it);
    //     long long int ans = 0, mod = 1e9+7;
    //     for(auto it:map){
    //         long long int val = it.second;
    //         val = (val*(val-1)/2)%map;
    //         ans = (ans + val)%mod;
    //     }
        
    //     return ans;
    // }

    int rev(int n){
        int res = 0;
        while(n){
            res = res*10 + n%10;
            n /= 10;
        }
        return res;
    }

    int countNicePairs(vector<int>& nums){
        unordered_map<int, int> map;
        int res = 0;
        unsigned int mod = 1e9+7;
        for(auto &it:nums){
            int diff = it - rev(it);
            
            if(map.find(diff) == map.end())
                map[diff] = 0;
            else{
                map[diff]++;
                res = (res+map[diff])%mod;
            }
        }
        return res%mod;
    }
};