// Problem Name: Invert the Binary Tree
// Problem Link: https://www.interviewbit.com/problems/invert-the-binary-tree/

void rec(TreeNode* &root){
    if(!root) return;
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    rec(root->left); rec(root->right);
    return;
}
TreeNode* Solution::invertTree(TreeNode* root){
    if(!root) return root;
    rec(root); return root;
    
}
