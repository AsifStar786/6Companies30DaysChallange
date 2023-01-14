//  Question #1 of challenge #2(Goldman Sachs)
//  Name - Max Points on a line..
//  LeetCode #149

#include<bits/stdc++.h>
class Solution {
public:
    int maxPoints(vector<vector<int>>& p){
        int n = p.size();
        if(n < 3) return p.size();

        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i == j) continue;
                int temp = 2;
                for(int k = 0; k < n; ++k){
                    if(k != i && k != j && (p[j][0]-p[i][0])*(p[k][1]-p[j][1]) == (p[j][1]-p[i][1])*(p[k][0]-p[j][0]))
                        ++temp;
                }
                ans = max(ans, temp);
            }
        }

        return ans;
    }
};