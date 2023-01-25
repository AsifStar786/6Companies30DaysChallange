//  Question #8 of challenge #5(Google)
//  Name - Pick index based on weight
//  LeetCode #528

class Solution {
    vector<int> vec;
public:
    Solution(vector<int>& w) {
        vec.push_back(w[0]);
        for(int i = 1; i < w.size(); i++) 
            vec.push_back(vec.back()+w[i]);
    }

    int pickIndex() {
        int x = rand() % vec.back();
        return upper_bound(vec.begin(), vec.end(), x) - vec.begin();
    }
};