//  Question #10 of challenge #6(Amazon)
//  Name - Maximum Matching Subsequence
//  LeetCode #792


class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> store(26);
        for(int i = 0; i < s.size(); i++)
            store[s[i]-'a'].push_back(i);

        int ans = words.size();
        for(auto w:words){
            int prev = -1;

            for(auto c:w){
                int i = c-'a';
                auto it = upper_bound(store[i].begin(), store[i].end(), prev);
                if(it == store[i].end()){
                    ans--;
                    break;
                }
                else
                    prev = *it;
            }
        }
        return ans;
    }
};