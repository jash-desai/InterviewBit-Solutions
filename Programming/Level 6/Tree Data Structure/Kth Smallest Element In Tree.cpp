// Problem Name: Kth Smallest Element In Tree
// Problem Link: https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

/*
int Solution::kthsmallest(TreeNode* root, int k){
    vector<int> ino; stack<TreeNode*> st; st.push(root);
    while(st.size()){
        auto curr = st.top();
        if(curr->left){
            st.push(curr->left);
            curr->left = NULL; continue;
        }
        if(curr){
            ino.push_back(curr->val); st.pop();
        }
        if(curr->right){
            st.push(curr->right);
            curr->right = NULL; continue;
        }
    }
    return ino[k-1];
}
*/
int Solution::kthsmallest(TreeNode* root, int k) {
    stack<TreeNode*>st;
    TreeNode* curr = root;
    while(curr || st.size()){
        while(curr){
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop(); k--;
        if(!k) return curr->val;
        curr = curr->right;
    }
    return -1;
}
