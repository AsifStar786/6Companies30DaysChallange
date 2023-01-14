//  Question #15 of challenge #2(Goldman Sachs)
//  Name - Maximum good peoples
//  LeetCode #2151

#include<bits/stdc++.h>
class Solution {
    int ans = 0, n;
    bool valid(vector<bool> &v, vector<vector<int>>& st){
        for(int i = 0; i < n; i++){
            if(v[i] == 0) continue;
            for(int j = 0; j < n; j++){
                if(st[i][j] != 2 && st[i][j] != v[j]) return false;
            }
        }
        return true;
    }

    void dfs(vector<bool> &v, int cnt, vector<vector<int>>& st){
        if(v.size() == n){
            if(valid(v, st))
                ans = max(ans, cnt);
            return ;
        }
        v.push_back(0);
        dfs(v, cnt, st);
        v.back() = 1;
        dfs(v, ++cnt, st);
        v.pop_back();
    }

public:
    int maximumGood(vector<vector<int>>& st) {
        vector<bool> v;
        n = st.size();
        dfs(v, 0, st);
        return ans;
    }
};