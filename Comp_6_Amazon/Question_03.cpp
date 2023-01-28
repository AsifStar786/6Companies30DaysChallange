//  Question #3 of challenge #6(Amazon)
//  Name - Split into max number of substrings
//  LeetCode #1593

class Solution {
public:
    unordered_map<string, bool> map;
    int ans = 0;

    void solve(string s, int ind, int cnt){
        if(ind == s.size()){
            ans = max(ans, cnt);
            return;
        }

        for(int i = ind+1; i <= s.size(); i++){
            string st = s.substr(ind, i-ind);
            if(map[st] == 1) continue;

            map[st] = 1;
            solve(s, i, cnt+1);
            map[st] = 0;
        } 
    }

    int maxUniqueSplit(string s) {
        solve(s, 0, 0);
        return ans;
    }
};