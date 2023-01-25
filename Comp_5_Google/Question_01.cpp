//  Question #1 of challenge #5(Google)
//  Name - Maximum consecutive floors without special floors
//  LeetCode #2274

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int ans = special[0] - bottom;

        for(int i = 1; i < special.size(); i++){
            ans = max(ans, special[i]-special[i-1]-1);
        }

        return max(ans, top-special.back());
    }
};