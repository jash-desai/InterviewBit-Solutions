// Problem Name: Flatten Binary Tree to Linked List
// Problem Link: https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/

TreeNode* Solution::flatten(TreeNode* root){
    TreeNode* curr = root;
    while(curr){
        if(curr->left){
            TreeNode* prev = curr->left;
            while(prev->right) prev = prev->right;
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
    return root;
}