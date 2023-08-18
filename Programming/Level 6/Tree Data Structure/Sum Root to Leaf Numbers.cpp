// Problem Name: Sum Root to Leaf Numbers
// Problem Link: https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/

bool check(TreeNode* root){
    return (!root->left and !root->right);
}
int Solution::sumNumbers(TreeNode* root) {
    if(!root) return 0;
    int ans{0};
    queue<pair<TreeNode*, long long int>> q; q.push({root, 0});
    while(q.size()){
        auto p = q.front(); q.pop();
        auto curr = p.first; long long int num = p.second;
        num = (num*10)%1003;  num = (num + curr->val)%1003;
        if(check(curr)) ans = (ans + num)%1003;
        if(curr->left) q.push({curr->left, num});
        if(curr->right) q.push({curr->right, num});
    }
    return ans%1003;
}