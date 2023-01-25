//  Question #6 of challenge #5(Google)
//  Name - Distinct echo substrings
//  LeetCode #1316

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set<string> s;

        for (auto i = 1; i < text.size() - 1; i++){
            for (auto sz = 1; i - sz >= 0 && i + sz - 1 < text.size(); ++sz) {
                if (text.compare(i - sz, sz, text, i, sz) == 0)
                    s.insert(text.substr(i, sz));
            }
        }
        
        return s.size();
    }
};