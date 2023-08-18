// Problem Name: Diagonal Traversal
// Problem Link: https://www.interviewbit.com/problems/diagonal-traversal/

vector<int> Solution::solve(TreeNode* root){
    if(!root) return {};
    queue<TreeNode*> q; vector<int> ans;
    q.push(root);
    while(q.size()){
        auto curr = q.front(); q.pop();
        while(curr){
            if(curr->left) q.push(curr->left);
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }
    return ans;
}
