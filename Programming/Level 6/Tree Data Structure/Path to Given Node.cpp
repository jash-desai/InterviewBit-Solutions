// Problem Name: Path to Given Node
// Problem Link: https://www.interviewbit.com/problems/path-to-given-node/

vector<int> Solution::solve(TreeNode* root, int k) {
    if(!root) return {};
    if(root->val == k) return {root->val};
    queue<pair<TreeNode*, vector<int>>> q;
    q.push({root, {}});
    while(q.size()){
        auto x = q.front(); q.pop();
        auto curr = x.first; auto temp = x.second;
        temp.push_back(curr->val);
        if(curr->val == k) return temp;
        if(curr->left){
            q.push({curr->left, temp});
        }
        if(curr->right){
            q.push({curr->right, temp});
        }
    }
    return {-1};
}