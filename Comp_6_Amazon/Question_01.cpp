//  Question #1 of challenge #6(Amazon)
//  Name - Shuffle an array
//  LeetCode #384

class Solution {
    vector<int> mainV, tempV;
    int n;
public:
    Solution(vector<int>& nums) {
        mainV = tempV = nums;
        n = nums.size();
    }
    
    vector<int> reset(){
        return mainV;
    }
    
    vector<int> shuffle(){
        int one = rand()%n, two = rand()%n;
        swap(tempV[one], tempV[two]);

        return tempV;
    }
};