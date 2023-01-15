//  Question #1 of challenge #3(Adobe)
//  Name - Fraction to reccuring decimal
//  LeetCode #166

class Solution {
    unordered_map<int, int> map;
    bool neg = 0;
    string makeNum(int num, string ans){
        int n = map[num];
        string a = ans.substr(0,n), b = ans.substr(n);
        ans = a + "(" + b + ")";
        return neg ? "-" + ans : ans;
    }

public:
    string fractionToDecimal(long long int num, long long int denom) {
        if(num == 0) return "0";
        if(num < 0 && denom < 0){
            num = abs(num);
            denom = abs(denom);
        }
        else if(num < 0) neg = 1, num = abs(num);
        else if(denom < 0) neg = 1, denom = abs(denom);

        long long int div = num/denom;
        num %= denom;
        string ans = to_string(div);
        if(!num) return neg ? "-" + ans : ans;
        ans += '.';

        map[num] = ans.size();
        num *= 10;

        while(num){
            div = num/denom;
            ans += (div+'0');
            num %= denom;
            if(!num) break;
            if(map[num] > 0){
                return makeNum(num, ans);
            }
            map[num] = ans.size();
            num *= 10;
        }
        return neg ? "-" + ans : ans;
    }
};