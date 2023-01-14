// Question #7 of Challange 1
// Question Name:-
// Course Sceduling
// Leetcode #207

#include<bits.stdc++.h>
class Solution {
public:
    vector<bool> vis, pathVis;
    
    bool Cycle(int v, vector<vector<int>>& adj){
        vis[v] = 1;
        pathVis[v] = 1;
        
        for(auto it:adj[v]){
            if(pathVis[it])
                return true;
            if(!vis[it] && Cycle(it, adj)){
                return true;
            }
        }
        
        pathVis[v] = 0;
        
        return false;
    }
    
    void setAdj(vector<vector<int>>& pre, vector<vector<int>> &adj){
        for(auto it:pre){
            adj[it[0]].push_back(it[1]);
        }    
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vis.resize(n);
        pathVis.resize(n);
        vector<vector<int>> adj(n);
        setAdj(pre, adj);
        
        for(int i = 0; i < n; i++){
            if(!vis[i] && Cycle(i, adj))
                return false;
            
        }
        
        return true;
    }
};
