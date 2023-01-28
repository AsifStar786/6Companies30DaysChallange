// Question #8 of Challange 1
// Question Name:- Optimal path in a tree
// Leetcode # 2467

class Solution {
    vector<int> timeMap; // to store timeStamp of bob's move
    vector<bool> vis; // visited array... as usual
    unordered_map<int, vector<int>> g; // the actual 2-dirc graph
    int ans = INT_MIN; // answer as lowest value

    bool callForBob(int bob, int sec){
        //  root reached..
        if(bob == 0){
            timeMap[bob] = sec;
            return true; //  acknowledge that it's reached !
        }

        vis[bob] = 1;
        bool canReach = 0; //  denotes if it can reach the root
        for(auto it:g[bob]){
            if(vis[it]) continue;
            if(callForBob(it, sec+1) == true){
                canReach = 1;
                break;
            }
        }
        vis[bob] = 0;

        if(canReach == 1){ //  if can reach root, save the time
            timeMap[bob] = sec;
            return true;
        }
        return false; //  else can't reach
    }

    void callForAlice(int node, int sec, int cost, vector<int> &amount){
        vis[node] = 1;
        // this means alice comes before bob, then total cost/reward goes to alice
        if(timeMap[node] > sec)
            cost += amount[node];
        //  this means both came in same time
        else if(timeMap[node] == sec)
            cost += (amount[node])/2;
        //  else the gate is open, then no effect on cost
        
        for(auto it:g[node]){
            if(vis[it]) continue;
            //  going towards every child
            callForAlice(it, sec+1, cost, amount);
        }
        vis[node] = 0;
        //  base cond. reched in a child
        if(node != 0 && g[node].size() == 1){
            ans = max(ans, cost);
        }
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        // forming the tree as a undirected graph
        for(auto it:edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        // visited array of size n
        vis.resize(n);
        timeMap.resize(n, INT_MAX); // it's assumed that never reached 

        int sec = 0; // time starts now...!!
        callForBob(bob, sec); // bob travarses towards root

        callForAlice(0, sec, 0, amount); // alice travarses towards child,cost 0

        return ans;
    }
};
