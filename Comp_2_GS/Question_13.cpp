//  Question #13 of challenge #2(Goldman Sachs)
//  Name - Get Biggest Three Rhombus Sums in a Grid
//  LeetCode #1878

#include<bits/stdc++.h>
class Solution {
    int one = 0, two = 0, three = 0;
    int m, n;
    void makeMax(int x){
        if(x > one)
            three = two,two = one, one = x;
        else if(x < one && x > two)
            three = two, two = x;
        else if(x < two && x > three)
            three = x;
    }

    void solve(vector<vector<int>> &grid, pair<int, int> p1, pair<int, int> p2, bool grow, int prev){
        int i = p1.first, j = p1.second, k = p2.first, l = p2.second;
        if(i == m || j < 0 || l == n) return;
        if(p1 == p2){
            int val = grid[i][j];
            if(grow){
                makeMax(val);
                solve(grid, {i+1, j-1}, {k+1, l+1}, 1, val);
            }
            else{
                makeMax(val + prev);
            }
            return;
        }

        prev = grid[i][j] + grid[k][l] + prev;
        if(grow){
            //  we can grow here..
            solve(grid, {i+1, j-1}, {k+1, l+1}, 1, prev);
        }
        solve(grid, {i+1, j+1}, {k+1, l-1}, 0, prev); //  shrinking...
    }

public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                solve(grid, {i, j}, {i, j}, 1, 0);
            }
        }

        vector<int> ans;
        if(one) ans.push_back(one);
        if(two) ans.push_back(two);
        if(three) ans.push_back(three);
        return ans;
    }
};