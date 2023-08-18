// Problem Name: Vertical Order traversal of Binary Tree
// Problem Link: https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/

vector<vector<int>> Solution::verticalOrderTraversal(TreeNode* root){
    if(!root) return {};
    map<int, vector<int>> mp; vector<vector<int>> ans;
    queue<pair<TreeNode*, int>> q; q.push({root, 0});
    while(q.size()){
        auto x = q.front(); q.pop();
        int lvl = x.second; auto curr = x.first;
        mp[lvl].push_back(curr->val);
        if(curr->left) q.push({curr->left, lvl-1});
        if(curr->right) q.push({curr->right, lvl+1});
    } 
    for(auto x : mp){
        ans.push_back(x.second);
    }
    return ans;
}