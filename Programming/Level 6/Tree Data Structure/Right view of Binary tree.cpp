// Problem Name: Right view of Binary tree
// Problem Link: https://www.interviewbit.com/problems/right-view-of-binary-tree/

vector<int> Solution::solve(TreeNode* root){
    if(!root) return {};
    vector<int> ans; map<int, int> mp;
    queue<pair<TreeNode*, int>> q; q.push({root, 0});
    while(q.size()){
        int sz = q.size();
        while(sz--){
            auto x = q.front(); q.pop();
            auto curr = x.first; int lvl = x.second;
            mp[lvl] = curr->val;
            if(curr->left) q.push({curr->left, lvl+1});
            if(curr->right) q.push({curr->right, lvl+1});
        }
    }
    for(auto x : mp){
        ans.push_back(x.second);
    }
    return ans;
}
