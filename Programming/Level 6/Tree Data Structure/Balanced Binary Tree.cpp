// Problem Name: Balanced Binary Tree
// Problem Link: https://www.interviewbit.com/problems/balanced-binary-tree/

int rec(TreeNode* root){
    if(!root) return 1;
    int lh = rec(root->left);
    int rh = rec(root->right);
    if(lh==-1 or rh==-1 or abs(lh-rh)>1) return -1;
    return 1 + max(lh, rh);
}
int Solution::isBalanced(TreeNode* root){
    if(!root) return 1;
    return (rec(root)!=-1);
}
