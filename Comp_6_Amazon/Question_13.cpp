//  Question #13 of challenge #6(Amazon)
//  Name - Top K frequent words
//  LeetCode #692

class Solution {
public:
    static bool compare(pair<string, int> p1, pair<string, int> p2){
		if (p1.second == p2.second)
			return p1.first < p2.first;
 
		return p1.second > p2.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++)
            m[words[i]]++;

        vector<pair<string,int>> v(m.begin(),m.end());
        vector<string> ans;
        sort(v.begin(),v.end(),compare);
  
        int i=0;
        while(i<v.size() && k){
            pair<string,int> p=v[i];
            ans.push_back(p.first);
            k--;
            i++;
        }
        return ans;
    }
};