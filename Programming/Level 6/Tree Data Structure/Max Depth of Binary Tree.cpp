// Problem Name: Max Depth of Binary Tree
// Problem Link: https://www.interviewbit.com/problems/max-depth-of-binary-tree/

int Solution::maxDepth(TreeNode* root){
    if(!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
