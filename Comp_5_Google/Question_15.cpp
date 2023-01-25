//  Question #15 of challenge #5(Google)
//  Name - Maximum Compatibility Sum..
//  LeetCode #1947

class Solution{
    int ans = 0, m, n;
    vector<bool> taken;
    int calculate(vector<int> &st, vector<int> &mt){
        int i = 0, c = 0;
        while(i < n){
            if(st[i] == mt[i]) c++;
            i++;
        }
        return c;
    }

    void solve(vector<vector<int>>& st, vector<vector<int>>& mt, int ind, int score){
        if(ind == m){
            ans = max(ans, score);
            return ;
        }

        for(int i = 0; i < m; i++){
            if(taken[i]) continue;
            int curr = calculate(st[ind], mt[i]);
            taken[i] = 1;
            solve(st, mt, ind+1, score+curr);
            taken[i] = 0;
        }
    }

    public:
    int maxCompatibilitySum(vector<vector<int>>& st, vector<vector<int>>& mt) {
        n = st[0].size();
        m = st.size();
        taken.resize(m);

        solve(st, mt, 0, 0);
        return ans;
    }
};