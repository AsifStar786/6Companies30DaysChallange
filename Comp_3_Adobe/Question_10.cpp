//  Question #10 of challenge #3(Adobe)
//  Name - Maximum matrix sum
//  LeetCode #1975

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long int sum = 0, cnt = 0, mini = INT_MAX;

        for(auto it:matrix){
            for(auto jt:it){
                if(jt < 0) cnt++;
                int val = abs(jt);
                if(mini > val) mini = val;
                sum += val;
            }
        }
        return cnt&1 ? sum - 2*mini : sum; 
    }
};