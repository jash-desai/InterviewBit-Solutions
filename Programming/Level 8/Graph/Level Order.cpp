// Problem Name: Level Order
// Problem Link: https://www.interviewbit.com/problems/level-order/

vector<vector<int> > Solution::levelOrder(TreeNode* root){
    if(!root) return {};
    vector<vector<int>> ans;
    queue<TreeNode*> q; q.push(root);
    while(q.size()){
        int n = q.size(); vector<int> temp;
        while(n--){
            auto curr = q.front(); q.pop();
            temp.push_back(curr->val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        ans.push_back(temp);
    }
    return ans;
}
