// Problem Name: Burn a Tree
// Problem Link: https://www.interviewbit.com/problems/burn-a-tree/

int Solution::solve(TreeNode* root, int k){
    unordered_set<TreeNode*> st;
    map<int, TreeNode*> mp; queue<TreeNode*> q; q.push(root);
    TreeNode* begin = NULL; mp[root->val] = NULL;
    while(q.size()){
        auto curr = q.front(); q.pop();
        if(curr->val == k) begin = curr;
        if(curr->left){
            mp[curr->left->val] = curr;
            q.push(curr->left);
        }
        if(curr->right){
            mp[curr->right->val] = curr;
            q.push(curr->right);
        }
    } int ans{0};
    queue<pair<TreeNode*, int>> qp; qp.push({begin, 0});
    while(qp.size()){
        auto x = qp.front(); qp.pop();
        auto curr = x.first; int t = x.second;
        ans = max(ans, t);
        if(curr->left and !st.count(curr->left)){
            qp.push({curr->left, t+1});
            st.insert(curr->left);
        }
        if(curr->right and !st.count(curr->right)){
            qp.push({curr->right, t+1});
            st.insert(curr->right);
        }
        auto par = mp[curr->val];
        if(par and !st.count(par)){
            qp.push({par, t+1});
            st.insert(par);
        }
    }
    return ans;
}
