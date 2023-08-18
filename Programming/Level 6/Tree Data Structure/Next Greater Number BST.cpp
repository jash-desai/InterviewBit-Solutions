// Problem Name: Next Greater Number BST
// Problem Link: https://www.interviewbit.com/problems/next-greater-number-bst/

TreeNode* Solution::getSuccessor(TreeNode* root, int k) {
    TreeNode* curr = root, *ans = NULL;
    while(curr){
        if(curr->val>k){
            ans = curr;
            curr = curr->left;
        }else curr = curr->right;
    }
    return ans;
}
