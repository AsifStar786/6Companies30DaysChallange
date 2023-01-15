//  Question #3 of challenge #3(Adobe)
//  Name - K-th smallest lexicographical Order...
//  LeetCode #440

#define ll long long int
class Solution {
public:
   int findKthNumber(int n, int k){
        ll result = 1;
        for(--k; k > 0; ){
            ll count = 0;
            for (ll first = result, last = first+1; first <= n; first *= 10, last *= 10)
                count += (min(n + 1LL, last) - first);
            
            if (k >= count){   
                ++result;
                k -= count;
            }
            else{   
                result *= 10;
                --k;
            }
        }
        return result;
    }
};