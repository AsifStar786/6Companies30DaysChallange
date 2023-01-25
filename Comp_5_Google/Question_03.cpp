//  Question #3 of challenge #5(Google)
//  Name - Sort the array (done by Merge Sort)
//  LeetCode #912

class Solution {
    void merge(vector<int>& nums, int l, int mid, int r){
        vector<int> temp;
        int i = l, j = mid+1;

        while(i <= mid && j <= r){
            if(nums[i] < nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while(i <= mid) temp.push_back(nums[i++]);
        while(j <= r) temp.push_back(nums[j++]);

        i = l;
        for(auto it:temp) nums[i++] = it;
    }

    void mSort(vector<int> &nums, int l, int r){
        if(l >= r) return;
        int mid = l + (r-l)/2;
        mSort(nums, l, mid);
        mSort(nums, mid+1, r);
        merge(nums, l, mid, r);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mSort(nums, 0, nums.size()-1);
        return nums;
    }
};