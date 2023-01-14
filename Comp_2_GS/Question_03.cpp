//  Question #3 of challenge #2(Goldman Sachs)
//  Name - Factorial Trailing Zeroes
//  LeetCode #172

#include<bits/stdc++.h>
class Solution {
public:
    int trailingZeroes(int n) {
        return (n/5) + (n/25) + (n/125) + (n/625) + (n/3125);
    }
};