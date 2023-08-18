// Problem Name: Vertical Sum of a Binary Tree
// Problem Link: https://www.interviewbit.com/problems/vertical-sum-of-a-binary-tree/

#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode* root){
    if(!root) return {};
    map<int, vector<int>> mp;
    queue<pair<TreeNode*, int>> q; q.push({root, 0});
    while(q.size()){
        auto x = q.front(); q.pop();
        int lvl = x.second; auto curr = x.first;
        mp[lvl].push_back(curr->val);
        if(curr->left) q.push({curr->left, lvl-1});
        if(curr->right) q.push({curr->right, lvl+1});
    } vector<int> ans;
    for(auto x : mp){
        int temp = accumulate(x.second.begin(), x.second.end(), 0);
        ans.push_back(temp);
    }
    return ans;
}
vector<int> Solution::verticalSum(TreeNode* root){
    if(!root) return {};
    return verticalOrderTraversal(root);
}
