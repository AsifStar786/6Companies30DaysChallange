//  Question #2 of challenge #5(Google)
//  Name - Maximum good peoples based on statement
//  LeetCode #2151

class Solution {
    int ans = 0, n;
    vector<bool> v;

    int check(vector<vector<int>> &s){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(v[i] == 0) continue;
            cnt++;
            for(int j = 0; j < n; j++){
                if(s[i][j] == 0 && v[j] == 1) return 0;
                if(s[i][j] == 1 && v[j] == 0) return 0;
            }
        }

        return cnt;
    }

    void solve(vector<vector<int>> &s, int ind){
        if(ind == n){
            int curr = check(s);
            ans = max(ans, curr);
            return;
        }
        v[ind] = 1;
        solve(s, ind+1);
        v[ind] = 0;

        solve(s, ind+1);
    }

public:
    int maximumGood(vector<vector<int>>& s) {
        n = s.size();
        v.resize(n);

        solve(s, 0);
        return ans;
    }
};