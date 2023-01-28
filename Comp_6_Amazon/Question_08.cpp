//  Question #8 of challenge #6(Amazon)
//  Name - Asteroid Destruction
//  LeetCode #2126


class Solution {
public:
    bool asteroidsDestroyed(long long int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int i = 0;
        while(i < asteroids.size()){
            if(mass < asteroids[i]) return 0;
            mass += asteroids[i++];
        }
        return true;
    }
};