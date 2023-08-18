// Problem Name: Identical Binary Trees
// Problem Link: https://www.interviewbit.com/problems/identical-binary-trees/

int Solution::isSameTree(TreeNode* a, TreeNode* b){
    if(!a and !b) return 1;
    if(!a or !b or a->val != b->val) return 0;
    if(isSameTree(a->left, b->left) and isSameTree(a->right, b->right)) return 1;
    return 0;
}
