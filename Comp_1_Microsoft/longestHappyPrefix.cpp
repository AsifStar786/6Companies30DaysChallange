// Question #12 of Challange 1
// Question Name:-
// Longest Happy Prefix of a string that is a prefix as well as a suffix
// Leetcode #1392

#include<bits/stdc++.h>
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n);
        int len = 0;

        for(int i = 1; i < n; ){
            if(s[i] == s[len]){
                lps[i++] = ++len;
            }
            else{
                if(len == 0) i++;
                else len = lps[len-1];
            }
        }
        
        return s.substr(0, lps.back());
    }
};
