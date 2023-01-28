//  Question #5 of challenge #6(Amazon)
//  Name - Maximum sum of an hourglass
//  LeetCode #2428


class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        
        for(int i = 1; i < m-1; i++){
            for(int j = 1; j < n-1; j++){
                int val = grid[i][j] + grid[i-1][j] + grid[i+1][j]+ grid[i-1][j-1]+ grid[i-1][j+1]+ grid[i+1][j-1] + grid[i+1][j+1];
                ans = max(ans, val);
            }
        }
        
        return ans;
    }
};