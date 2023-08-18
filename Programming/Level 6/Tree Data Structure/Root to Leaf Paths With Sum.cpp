// Problem Name: Root to Leaf Paths With Sum
// Problem Link: https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/

bool check(TreeNode* root){
    if(!root) return 0;
    return (!root->left and !root->right);
}
vector<vector<int>> Solution::pathSum(TreeNode* root, int k){
    if(!root) return {};
    vector<vector<int>> ans;
    queue< pair<pair<TreeNode*, vector<int>>, int> > q;
    q.push({{ root, {} }, 0});
    while(q.size()){
        auto x = q.front(); q.pop();
        auto curr = x.first.first; auto temp = x.first.second;
        auto currSum = x.second;
        temp.push_back(curr->val); currSum += curr->val;
        if(currSum == k and check(curr)){
            ans.push_back(temp);
            continue;
        }
        if(curr->left){
            q.push({{curr->left, temp}, currSum});
        }
        if(curr->right){
            q.push({{curr->right, temp}, currSum});
        }
    }
    return ans;
}
