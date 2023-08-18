// Problem Name: Preorder Traversal
// Problem Link: https://www.interviewbit.com/problems/preorder-traversal/

vector<int> Solution::preorderTraversal(TreeNode* root){
    if(!root) return {}; vector<int> ans;
    stack<TreeNode*> st; st.push(root);
    while(st.size()){
        auto curr = st.top();
        if(curr){
            ans.push_back(curr->val);
            st.pop();
        }
        if(curr->right){
            st.push(curr->right);
            curr->right = NULL;
        }
        if(curr->left){
            st.push(curr->left);
            curr->left = NULL;
        }
    }
    return ans;
}
