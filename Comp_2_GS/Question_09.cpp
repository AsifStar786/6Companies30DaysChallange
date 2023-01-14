//  Question #9 of challenge #2(Goldman Sachs)
//  Name - IPO(Intitial Public Offering)
//  LeetCode #502

#include<bits/stdc++.h>
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& pro, vector<int>& cap) {
        vector<pair<int, int>> v;
        int n = cap.size();
        for(int i = 0; i < n; i++) v.push_back({cap[i], pro[i]});
        sort(v.begin(), v.end());

        int i = 0;
        priority_queue<int> prio;
        while(i < n && k){
            if(v[i].first <= w)
                prio.push(v[i++].second);
            else if(prio.size()){
                    w += prio.top();
                    prio.pop();
                    k--;
                }
            else return w;
        }

        while(prio.size() && k--){
            w += prio.top();
            prio.pop();
        }
        
        return w;
    }
};