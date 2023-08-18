// Problem Name: Symmetric Binary Tree
// Problem Link: https://www.interviewbit.com/problems/symmetric-binary-tree/

bool fxn(TreeNode* a, TreeNode* b){
    if(!a and !b) return 1;
    if(!a or !b or a->val != b->val) return 0;
    return (fxn(a->left, b->right) and fxn(a->right, b->left));
}
int Solution::isSymmetric(TreeNode* root) {
    if(!root) return 1;
    return fxn(root->left, root->right);
}
