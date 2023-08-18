// Problem Name: Covered / Uncovered Nodes
// Problem Link: https://www.interviewbit.com/problems/covered-uncovered-nodes/

long Solution::coveredNodes(TreeNode* A) {
    long u_sum = 0, c_sum = 0;
    queue<TreeNode*> q; q.push(A);
    while(!q.empty()){
        int size = q.size();
        for(int i=0 ; i<size ; i++){
            TreeNode* temp = q.front(); q.pop();
            if(i == 0 or i == size-1) u_sum += temp->val;
            else if( i != 0 and i != size-1){
                c_sum += temp->val;
            }
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    long diff = abs(u_sum-c_sum);
    return diff;
}