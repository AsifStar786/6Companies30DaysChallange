//  Question #12 of challenge #4(Flipkart)
//  Name - Check if a string contains all codes of size K
//  LeetCode #1461

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() <= k) return 0;
        long long total = pow(2, k), num = 0;
        unordered_map<int, bool> map;
        int ind = s.size()-1;
        for(int i = 0; i < k; i++){
            num += pow(2, i)*(s[ind--]-'0');
        }
        map[num] = 1;
        total --;

        while(ind >= 0){
            num /= 2;
            if(s[ind--] == '1'){
                num += pow(2, k-1);
            }
            if(!map[num]) total--;
            map[num] = 1;
        }
        
        return !total;
    }
};