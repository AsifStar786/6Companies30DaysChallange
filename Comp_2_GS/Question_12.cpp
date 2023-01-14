//  Question #12 of challenge #2(Goldman Sachs)
//  Name - All elements in two BST
//  LeetCode #1305

#include<bits/stdc++.h>
class Solution {
    vector<int> ans, one, two;

    void in1(TreeNode* root){
        if(!root) return;
        in1(root -> left);
        one.push_back(root -> val);
        in1(root -> right);
    }void in2(TreeNode* root){
        if(!root) return;
        in2(root -> left);
        two.push_back(root -> val);
        in2(root -> right);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        in1(root1), in2(root2);

        ans.resize(one.size() + two.size());
        int i = 0, j = 0, k = 0;
        while(i < one.size() && j < two.size()){
            if(one[i] <= two[j])
                ans[k++] = one[i++];
            else ans[k++] = two[j++];
        }
        while(i < one.size()) ans[k++] = one[i++];
        while(j < two.size()) ans[k++] = two[j++];
        return ans;
    }
};