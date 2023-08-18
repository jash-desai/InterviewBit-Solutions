// Problem Name: Construct BST from Preorder
// Problem Link: https://www.interviewbit.com/problems/construct-bst-from-preorder/

map<int, int> mp;
TreeNode* rec(vector<int>&pre, int ps, int pe, vector<int>&ino, int is, int ie){
    if(is>ie or ps>pe) return NULL;
    TreeNode* root = new TreeNode(pre[ps]);
    int idx = mp[root->val];
    int ll = idx-is;
    root->left = rec(pre, ps+1, ps+ll, ino, is, idx-1);
    root->right = rec(pre, ps+ll+1, pe, ino, idx+1, ie);
    return root;
}
TreeNode* buildTree(vector<int> &pre, vector<int> &ino){
    mp.clear(); for(int i=0; i<ino.size(); i++) mp[ino[i]] = i;
    int ps = 0, pe = pre.size()-1, is = 0, ie = ino.size()-1;
    return rec(pre,ps,pe,ino,is,ie);
}
TreeNode* Solution::constructBST(vector<int> &pre){
    vector<int> ino = pre; sort(ino.begin(), ino.end());
    return buildTree(pre, ino);
}
