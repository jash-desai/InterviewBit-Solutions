// Problem Name: Path Sum
// Problem Link: https://www.interviewbit.com/problems/path-sum/

bool check(TreeNode* root){
    if(!root) return 0;
    return (!root->left and !root->right);
}
// /*
int Solution::hasPathSum(TreeNode* root, int k){
    if(!root and k) return 0;
    queue<pair<TreeNode*, int>> q; q.push({root, root->val});
    while(q.size()){
        auto x = q.front(); q.pop();
        auto curr = x.first; int currSum = x.second;
        if(currSum==k and check(curr)) return 1;
        if(curr->left){
            q.push({curr->left, currSum + curr->left->val});
        }
        if(curr->right){
            q.push({curr->right, currSum + curr->right->val});
        }
    }
    return 0;
}
// */