//  Question #8 of challenge #4(Flipkart)
//  Name - Closest Prime...
//  LeetCode #2523

class Solution {
public:
    vector<int> closestPrimes(int left, int right){
        int mx = 1000000;
        vector<bool> p(mx+1, 1);
        p[0] = p[1] = 0;

        for(int i = 2; i*i <= mx; i++){
            for(int j = i*i; j <= mx; j += i){
                p[j] = false;
            }
        }
        vector<int> primes;
        for(int i = 2; i <= mx; i++){
            if(p[i] && i >= left && i <= right) primes.push_back(i);
        }
        
        int diff = INT_MAX;
        vector<int> v = {-1, -1};
        if(primes.size() < 2) return v;
        for(int i = 0; i < primes.size()-1; i++){
            if(diff > primes[i+1]-primes[i]){ 
                diff = primes[i+1]-primes[i];
                v = {primes[i], primes[i+1]};
            }
        }
        return v;
    }
};