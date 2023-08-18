// Problem Name: Nodes at Distance K
// Problem Link: https://www.interviewbit.com/problems/nodes-at-distance-k/

vector<int> Solution::distanceK(TreeNode* root, int v, int k){
    if(!root) return {};
    TreeNode* begin; map<int, TreeNode*> mp;
    queue<TreeNode*> q; q.push(root); mp[root->val] = NULL;
    while(q.size()){
        auto curr = q.front(); q.pop();
        if(curr->val == v) begin = curr;
        if(curr->left){
            q.push(curr->left); mp[curr->left->val] = curr;
        }
        if(curr->right){
            q.push(curr->right); mp[curr->right->val] = curr;
        }
    } vector<int> ans; unordered_set<TreeNode*> st;
    queue<pair<TreeNode*, int>> qp; qp.push({begin, 0}); st.insert(begin);
    while(qp.size()){
        auto p = qp.front(); qp.pop();
        auto curr = p.first; int t = p.second;
        if(t>k) continue;
        if(t==k){
            ans.push_back(curr->val);
            continue;
        }
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
