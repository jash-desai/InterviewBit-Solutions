// Problem Name: Inorder Traversal of Cartesian Tree
// Problem Link: https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/

TreeNode* build(vector<int>&A,int start,int end){
    if(start==end) return new TreeNode(A[start]);
    if(start>end) return NULL;
    int ind=-1, maxi = INT_MIN;
    for(int i=start; i<=end; i++){
        if(A[i]>maxi) ind=i, maxi = A[i];
    }
    TreeNode* root = new TreeNode(A[ind]);
    root->left = build(A,start,ind-1);
    root->right = build(A,ind+1,end);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A){
    int n=A.size();
    return build(A,0,n-1);
}
