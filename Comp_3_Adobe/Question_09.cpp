//  Question #9 of challenge #3(Adobe)
//  Name - Count no of node with value equal to average of its subtree
//  LeetCode #2265

class Solution {
public:
    int ans = 0;
    pair<int, int> solveRec(TreeNode* root){
        int sum = root -> val, cnt = 1;
        if(root -> right){
            pair<int, int> l = solveRec(root -> right);
            sum += l.first;
            cnt += l.second;
        }
        
        if(root -> left){
            pair<int, int> r = solveRec(root -> left);
            sum += r.first;
            cnt += r.second;
        }
        if(root -> val == sum/cnt) ans++;
        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        solveRec(root);
        return ans;
    }
};