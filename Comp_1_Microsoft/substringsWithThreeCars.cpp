// Question #15 of Challange 1
// Question Name:-
// number of substrings with at least one appearence of 'a', 'b' and 'c'
// Leetcode #1358

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0, i = 0;
        vector<int> tmp(3, 0);
        for(int  j = 0; j < s.size(); j++){
            tmp[s[j]-'a']++;

            while(tmp[0] && tmp[1] && tmp[2]){
                ans += s.size()-j;
                tmp[s[i]-'a']--;
                i++;
            }
        }
        
        return ans;
    }
};
