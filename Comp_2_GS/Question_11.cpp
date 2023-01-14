//  Question #11 of challenge #2(Goldman Sachs)
//  Name - invalid transaction...
//  LeetCode #1169

#include<bits/stdc++.h>
class Solution {
    class help{
        public:
        int time;
        int amount;
        string name;
        string city;
        help(string name, string city, int amount, int time){
            this -> time = time;
            this -> name = name;
            this -> city = city;
            this -> amount = amount;
        }
    };

    void decode(vector<help*> &v, string &s){
        string name, city;
        int time = 0, amount = 0, i = 0;

        while(s[i] != ','){
            name += s[i++];
        }i++;
        while(s[i] != ','){
            time = time*10 + s[i++]-'0';
        }i++;
        while(s[i] != ','){
            amount = amount*10 + s[i++] - '0';
        }i++;
        while(i < s.size()){
            city += s[i++];
        }

        v.push_back(new help(name, city, amount, time));
    }
public:
    vector<string> invalidTransactions(vector<string>& tr) {
        vector<help*> v;
        for(auto &it:tr)
            decode(v, it);
        // for(auto it:v) cout << it->name << endl;
        set<int> store;
        unordered_map<string, vector<int>> map;

        for(int i = 0; i < v.size(); i++){
            if(v[i] -> amount > 1000){
                store.insert(i);
                map[v[i] -> name].push_back(i);
            }

            vector<int> temp = map[v[i] -> name];
            for(auto &it:temp){
                if(v[it] -> city != v[i] -> city && abs((v[it] -> time) - (v[i] -> time)) <= 60){
                    store.insert(i), store.insert(it);
                }
            }
            map[v[i] -> name].push_back(i);
        }

        vector<string> ans;
        for(auto &i:store) ans.push_back(tr[i]);
        return ans;
    }
};