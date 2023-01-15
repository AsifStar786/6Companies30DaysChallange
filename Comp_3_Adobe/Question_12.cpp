//  Question #12 of challenge #3(Adobe)
//  Name - Shortest unsorted subarray...
//  LeetCode #581

class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0, r = 0;
        for(int i = 1; i < n; i++){
            if(arr[maxi] > arr[i]){
                r = i;
            }
            else maxi = i;
        }

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