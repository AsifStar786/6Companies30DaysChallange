//  Question #15 of challenge #4(Flipkart)
//  Name - House Robber III
//  LeetCode #337

class Solution {
    pair<int, int> solve(TreeNode* root){
        if(!root) return {0, 0};
        pair<int, int> l = solve(root -> left), r = solve(root -> right);
        int take = 0, notTake = 0;
        take = root -> val + l.second + r.second;
        notTake = max(l.first, l.second) + max(r.first, r.second);
        return {take, notTake};
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};