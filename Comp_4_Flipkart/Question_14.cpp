//  Question #14 of challenge #4(Flipkart)
//  Name - Custom sort string...
//  LeetCode #791


class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> map;
        for(auto it:s) map[it]++;

        string ans = "";
        for(auto &it:order){
            ans.append(map[it], it);
            map[it] = 0;
        }

        for(auto it:map)
            ans.append(it.second, it.first);

        return ans;
    }
};