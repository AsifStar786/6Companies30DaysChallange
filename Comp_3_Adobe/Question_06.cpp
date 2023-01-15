//  Question #6 of challenge #3(Adobe)
//  Name - Knight walk probability...
//  LeetCode #688

class Solution {
    vector<vector<vector<double>>> dp;
    vector<vector<int>> v = {{1,2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
    double solveDp(int n, int k, int row, int col){
        if(row < 0 || col < 0 || row >= n || col >= n) return 0;
        if(!k) return 1;
        if(dp[row][col][k] != -1) return dp[row][col][k];
        double res = 0;
        for(auto it:v){
            res += solveDp(n, k-1, row+it[0], col+it[1]);
        }
        return dp[row][col][k] = res/8;
    }

public:
    double knightProbability(int n, int k, int row, int column) {
        dp.resize(n, vector<vector<double>> (n, vector<double> (k+1, -1)));
        return solveDp(n, k, row, column);
    }
};