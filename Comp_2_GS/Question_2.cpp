//  Question #2 of challenge #2(Goldman Sachs)
//  Name - Valis Square
//  LeetCode #593

#include<bits/stdc++.h>
class Solution {
    int pyth(vector<int> &a, vector<int> &b){
        return (a[0] - b[0])*(a[0] - b[0]) + (a[1] - b[1])*(a[1] - b[1]);
    }
    int side = -1, dig = -1;

    bool check(int dis){
        if(side == dis || dig == dis) return 1;
        if(side == -1){
            side = dis;
            return true;
        }
        if(dig == -1){
            dig = dis;
            return true;
        }
        return false;
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(check(pyth(p1, p2)) == 0) return 0;
        if(check(pyth(p1, p3)) == 0) return 0;
        if(check(pyth(p1, p4)) == 0) return 0;
        if(check(pyth(p2, p3)) == 0) return 0;
        if(check(pyth(p2, p4)) == 0) return 0;
        if(check(pyth(p3, p4)) == 0) return 0;
        return side && dig && side != -1 && dig != -1;
    }
};