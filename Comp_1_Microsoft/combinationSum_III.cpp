// Second Question of Challange 1
// Question Name:-
// Combination Sum - III
// Leetcode #216

#include<bits/stdc++.h>

class Solution {
    //  universal answer to return 
    vector<vector<int>> ans;

    //  Recursive Function to calculate the answer
    void solve(int n, int k, int val, vector<int> &temp){
        if(!k){
            //  base case - if k digits are taken...
            if(!n) ans.push_back(temp);
            return;
        }

        //  starting digits from val till 9
        for(int i = val; i < 10; i++){
            temp.push_back(i);
            solve(n-i, k-1, i+1, temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;

        solve(n, k, 1, temp);
        return ans;
    }
};