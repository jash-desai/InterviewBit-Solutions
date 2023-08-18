// Problem Name: Postorder Traversal
// Problem Link: https://www.interviewbit.com/problems/postorder-traversal/

vector<int> Solution::postorderTraversal(TreeNode* root){
    if(!root) return {}; vector<int> ans;
    stack<TreeNode*> st; st.push(root);
    while(st.size()){
        auto curr = st.top();
        if(curr->left){
            st.push(curr->left);
            curr->left = NULL; 
            continue;
        }
        if(curr->right){
            st.push(curr->right);
            curr->right = NULL; 
            continue;
        }
        if(curr){
            ans.push_back(curr->val);
            st.pop();
        }
    }
    return ans;
}
