// Problem Name: Binary Tree From Inorder And Postorder
// Problem Link: https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/

map<int, int> mp;
TreeNode* rec(vector<int>&pos, int ps, int pe, vector<int>&ino, int is, int ie){
    if(is>ie or ps>pe) return NULL;
    TreeNode* root = new TreeNode(pos[pe]);
    int idx = mp[root->val];
    int ll = idx-is;
    root->left = rec(pos, ps, ps+ll-1, ino, is, idx-1);
    root->right = rec(pos, ps+ll, pe-1, ino, idx+1, ie);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &ino, vector<int> &pos){
    mp.clear(); for(int i=0; i<ino.size(); i++) mp[ino[i]] = i;
    int ps = 0, pe = pos.size()-1, is = 0, ie = ino.size()-1;
    return rec(pos,ps,pe,ino,is,ie);
}
