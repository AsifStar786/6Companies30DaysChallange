//  Question #5 of challenge #2(Goldman Sachs)
//  Name - Split Array into Consecutive Subsequences
//  LeetCode #659

#include<bits/stdc++.h>
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> map, tail;

        for(auto it:nums) map[it]++;

        for(auto it:nums){
            if(!map[it]) continue;
            map[it]--;

            if(tail[it-1]){
                tail[it-1]--;
                tail[it]++;
            }
            else{
                if(map[it+1] == 0 || map[it+2] == 0) return false;
                map[it+1]--, map[it+2]--;
                tail[it+2]++;
            }
        }

        return true;
    }
};