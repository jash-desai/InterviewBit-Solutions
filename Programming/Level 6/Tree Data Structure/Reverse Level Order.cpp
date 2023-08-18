// Problem Name: Reverse Level Order
// Problem Link: https://www.interviewbit.com/problems/reverse-level-order/

/*
vector<int> Solution::solve(TreeNode* root){
    vector<vector<int>> lot;
    queue<TreeNode*> q; q.push(root);
    while(q.size()){
        int sz = q.size(); vector<int> temp;
        while(sz--){
            auto x = q.front(); q.pop();
            temp.push_back(x->val);
            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
        }
        lot.push_back(temp);
    }
    vector<int> ans;
    for(int i=lot.size()-1; i>=0; i--){
        for(int x : lot[i]) ans.push_back(x);
    }
    return ans;
}
*/
vector<int> Solution::solve(TreeNode* root){
    vector<int> ans;
    queue<TreeNode*> q; q.push(root);
    while(q.size()){
        int sz = q.size(); 
        while(sz--){
            auto x = q.front(); q.pop();
            ans.push_back(x->val);
            if(x->right) q.push(x->right);
            if(x->left) q.push(x->left);
        }
    }
    return vector<int>(ans.rbegin(), ans.rend());
}
