//  Question #13 of challenge #4(Flipkart)
//  Name - Max area of island
//  LeetCode #695

class Solution {
    int ans = 0, m, n;
    int solve(vector<vector<int>>& grid, int row, int col){
        if(row < 0 || col < 0 || row == m || col == n || grid[row][col] == 0) return 0;
        grid[row][col] = 0;
        return 1 + solve(grid, row+1, col) +
            solve(grid, row-1, col) +
            solve(grid, row, col+1) +
            solve(grid, row, col-1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                ans = max(ans, solve(grid, i, j));
        
        return ans;
    }
};