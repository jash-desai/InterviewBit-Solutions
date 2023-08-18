// Problem Name: Sorted Array To Balanced BST
// Problem Link: https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/

TreeNode* fxn(const vector<int>&ino, int i, int j){
    if(i>j) return NULL;
    int m = i + ((j-i)>>1);
    TreeNode* root = new TreeNode(ino[m]);
    root->left = fxn(ino, i, m-1);
    root->right = fxn(ino, m+1, j);
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &ino){
    return fxn(ino, 0, ino.size()-1);
}
