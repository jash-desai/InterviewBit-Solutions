// Problem Name: ZigZag Level Order Traversal BT
// Problem Link: https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> ans;
    queue<TreeNode*> q; q.push(root); int cnt = 0;
    while(q.size()){
        int sz = q.size(); int n = sz;
        vector<int> temp(sz);  int i = 0;
        while(sz--){
            auto curr = q.front(); q.pop();
            if(!(cnt&1)){
                temp[i] = curr->val;
            }else{
                temp[n-i-1] = curr->val;
            }
            i++;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        cnt++;
        ans.push_back(temp);
    }
    return ans;
}
