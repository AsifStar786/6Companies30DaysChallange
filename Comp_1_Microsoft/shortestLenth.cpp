// Question #10 of Challange 1
// Question Name:-
// Shortest Unsorted Continuous Subarray
// Leetcode #581

class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        int n = arr.size();
        //  finding the rightMost index of the res. subarray
        int maxi = 0, r = 0;
        for(int i = 1; i < n; i++){
            if(arr[maxi] > arr[i]){
                r = i;
            }
            else maxi = i;
        }

        //  finding the leftMost index of the res. subarray
        int mini = n-1, l = n-1;
        for(int j = n-2; j >= 0; j--){
            if(arr[mini] < arr[j])
                l = j;
            else
                mini = j;
        }

        return (r-l > 0) ? r-l+1 : 0;
    }
};
