//  Question #4 of challenge #3(Adobe)
//  Name - Magical String
//  LeetCode #481

class Solution {
public:
    int magicalString(int n) {
        queue<bool> q;
        int cnt = 1;
        bool val = 1;
        n -= 3;
        q.push(0);

        while(n > 0){
            bool b = q.front();
            q.pop();
            if(val == 0){
                q.push(0);
                n--;
                if(!b) {
                    q.push(0); 
                    n--;
                }
                val = 1;
            }
            else{
                q.push(1);
                cnt++;
                n--;
                if(!b){
                    q.push(1);
                    cnt++;
                    n--;
                }
                val = 0;
            }
        }

        return (n < 0 && !val) ? --cnt : cnt;
    }
};