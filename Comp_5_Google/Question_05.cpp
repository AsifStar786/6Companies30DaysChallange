//  Question #5 of challenge #5(Google)
//  Name - count sorrounded islands
//  LeetCode #1254

class Solution {
    int m, n;
    void makeOne(vector<vector<int>> &grid, int row, int col){
        if(row < 0 || col < 0 || row == m || col == n || grid[row][col] == 1) return ;
        grid[row][col] = 1;
        makeOne(grid, row+1, col);
        makeOne(grid, row-1, col);
        makeOne(grid, row, col+1);
        makeOne(grid, row, col-1);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();

        for(int i = 0; i < m; i++) makeOne(grid, i, 0), makeOne(grid, i, n-1);
        for(int i = 0; i < n; i++) makeOne(grid, 0, i), makeOne(grid, m-1, i);

        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) makeOne(grid, i, j), cnt++;
            }
        }

        return cnt;
    }
};