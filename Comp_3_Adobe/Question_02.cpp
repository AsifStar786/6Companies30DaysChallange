//  Question #2 of challenge #3(Adobe)
//  Name - increasing triplet sequence...
//  LeetCode #334

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int low = INT_MAX;
        int mid = low, high = low;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < low) low = nums[i];
            else if(nums[i] < mid && nums[i] > low) mid = nums[i];
            else if(nums[i] > mid) return true;
        }

        return false;
    }
};