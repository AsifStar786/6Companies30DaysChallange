//  Question #8 of challenge #2(Goldman Sachs)
//  Name - Max points in archery competition
//  LeetCode #2212

#include<bits/stdc++.h>
class Solution {
    vector<int> ans;
    int ansCnt = 0, rem;
    void solve(int ar, int ind, vector<int> &al, vector<int> &v){
        if(ind == 12){
            int cnt = 0;
            for(int i = 0; i < 12; i++)
                if(v[i]) cnt += i;
            if(cnt > ansCnt){
                ans = v;
                ansCnt = cnt;
                rem = ar;
            }
            return ;
        }

        v.push_back(0);
        solve(ar, ind+1, al, v);
        v.pop_back();

        if(ar <= al[ind]) return; 
        v.push_back(al[ind]+1);
        solve((ar-al[ind]-1), (ind+1), al, v);
        v.pop_back();
    }

public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& al) {
        int ind = 0;
        vector<int> v;

        solve(numArrows, ind, al, v);
        ans[0] += rem;
        return ans;
    }
};