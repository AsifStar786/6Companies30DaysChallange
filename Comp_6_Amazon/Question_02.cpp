//  Question #2 of challenge #6(Amazon)
//  Name - Cheapest flights with K steps
//  LeetCode #787


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> g(n);
        for(auto it:flights)
            g[it[0]].push_back({it[1], it[2]});
        k++;

        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({src, 0});

        while(q.size() && k--){
            int s = q.size();
            while(s--){
                auto [u, d] = q.front(); q.pop();

                for(auto &[v, w]:g[u]){
                    if(dist[v] > d+w){
                        dist[v] = d+w;
                        q.push({v, d+w});
                    }
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};