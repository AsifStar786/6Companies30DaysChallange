// Question #14 of Challange 1
// Question Name:-
// minimum no of deletions made in array1 to make all element in array2 by min element of array1
// Leetcode #2344

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& nd) {
        //  value for storing the gcd of all the element in "nd" vector
        int val = nd[0];
        for(auto it:nd) val = __gcd(it, val); //  calculationg the gcd on whole array
        //  sorting the vector "nums" to get minimum values one by one...
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++){
            if(val%nums[i] == 0) return i;
            else if(val < nums[i]) return -1;
        }
        return -1;
    }
};
