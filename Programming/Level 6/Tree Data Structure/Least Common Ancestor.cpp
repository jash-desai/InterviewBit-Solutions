// Problem Name: Least Common Ancestor
// Problem Link: https://www.interviewbit.com/problems/least-common-ancestor/

TreeNode* rec(TreeNode* root, TreeNode* a, TreeNode* b){
    if(!root or root==a or root==b) return root;
    auto left = rec(root->left, a, b);
    auto right = rec(root->right, a, b);
    if(!left) return right;
    if(!right) return left;
    else return root;
}
int Solution::lca(TreeNode* root, int a, int b){
    if(!root) return -1;
    TreeNode* anode = NULL, *bnode = NULL;
    queue<TreeNode*> q; q.push(root);
    while(q.size()){
        auto curr = q.front(); q.pop();
        if(curr->val == a) anode = curr;
        if(curr->val == b) bnode = curr;
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    if(!anode or !bnode) return -1;
    return rec(root, anode, bnode)->val;
}