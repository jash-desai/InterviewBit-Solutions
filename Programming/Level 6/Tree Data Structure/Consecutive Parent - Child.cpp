// Problem Name: Consecutive Parent - Child
// Problem Link: https://www.interviewbit.com/problems/consecutive-parent-child/

int Solution::consecutiveNodes(TreeNode* root){
    if(!root) return 0; int ans(0);
    queue<TreeNode*> q; q.push(root);
    while(q.size()){
        auto curr = q.front(); q.pop();
        int k = curr->val;
        if(curr->left){
            if(abs(k - (curr->left->val)) == 1) ans++;
            q.push(curr->left);
        }
        if(curr->right){
            if(abs(k - (curr->right->val)) == 1) ans++;
            q.push(curr->right);
        }
    }
    return ans;
}
