//  Question #10 of challenge #5(Google)
//  Name - Network time delay
//  LeetCode #743

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n+1);
        for(auto it:times)
            g[it[0]].push_back({it[1], it[2]});

        vector<int> dist(n+1, 1e9);
        queue<int> q;
        q.push(k);
        dist[k] = 0;

        while(q.size()){
            int node = q.front();
            q.pop();
            
            for(auto it:g[node]){
                if(dist[it.first] > dist[node]+it.second){
                    dist[it.first] = dist[node]+it.second;
                    q.push(it.first);
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) 
            ans = max(ans, dist[i]);

        return ans == 1e9 ? -1 : ans;
    }
};