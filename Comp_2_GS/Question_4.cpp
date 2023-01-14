//  Question #4 of challenge #2(Goldman Sachs)
//  Name - Number of boomerangs
//  LeetCode #447

#include<bits/stdc++.h>
class Solution {
    int pyth(vector<int> &a, vector<int> &b){
        return pow(a[0]-b[0], 2) + pow(a[1]-b[1], 2);
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int n = p.size();
        if(n < 3) return 0;
        map<pair<int, int>, int> map;

        int cnt = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                // if(i == j) continue;
                int d = pyth(p[i], p[j]);
                map[{i, d}]++;
                map[{j, d}]++;
            }
        }

        for(auto it:map){
            int val = it.second;
            cnt += val*(val-1);
        }

        return cnt;
    }
};