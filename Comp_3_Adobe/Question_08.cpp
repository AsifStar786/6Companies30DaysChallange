//  Question #8 of challenge #3(Adobe)
//  Name - Gene Mutation...
//  LeetCode #433

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, bool> map;
        for(auto it:bank)
            map[it] = 1;
        if(!map[end]) 
            return -1;
        map[start] = 0;
        
        queue<string> ku;
        ku.push(start);
        int step = 0;
        
        while(ku.size()){
            int sz = ku.size();
            while(sz--){
                string st = ku.front();
                ku.pop();
                if(st == end) return step;
                map[st] = false;

                for(int i = 0; i < 8; i++){
                    string temp = st;
                    temp[i] = 'A';
                    if(map[temp]) ku.push(temp);

                    temp[i] = 'G';
                    if(map[temp]) ku.push(temp);

                    temp[i] = 'C';
                    if(map[temp]) ku.push(temp);

                    temp[i] = 'T';
                    if(map[temp]) ku.push(temp);
                }
            }
            step++;
        }
        
        return -1;
    }
};