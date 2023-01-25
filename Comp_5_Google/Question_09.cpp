//  Question #9 of challenge #5(Google)
//  Name - Maximum coins you can get
//  LeetCode #1561

class Solution {
public:
    int maxCoins(vector<int>& piles){
        sort(piles.begin(), piles.end());
        int cnt = piles.size()/3, ind = cnt*3-2, ans = 0;

        while(cnt){
            ans += piles[ind];
            cnt--;
            ind -= 2;
        }
        return ans;
    }
};