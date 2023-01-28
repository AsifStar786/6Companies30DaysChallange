// Third Question of Challange 1
// Name:- Bulls and Cows
// Leetcode #299

#include<bits/stdc++.h>
class Solution {
public:
    string getHint(string secret, string guess) {
        int x = 0, y = 0;
        //  we can get bulls by simply matching the digits...
        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == guess[i]) x++;
        }
        //  map for storing the digits in secret string
        unordered_map<int, int> map;
        for(auto it:secret) map[it]++;
        //  counting how many digits are in both the strings in any position
        for(auto it:guess) if(map[it]) y++, map[it]--;
        //  now cows = all matched digits - bulls
        return to_string(x) + "A" + to_string(y-x) + "B";
    }
}; 