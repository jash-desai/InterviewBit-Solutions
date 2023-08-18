// Problem Name: Convert Sorted List to Binary Search Tree
// Problem Link: https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/

TreeNode* rec(ListNode* head, ListNode* end){
    if(!head or head==end) return NULL;
    if(!head->next) return new TreeNode(head->val);
    ListNode* mid = head, *fast = head;
    while(fast!=end and fast->next!=end){
        fast=fast->next->next, mid=mid->next;
    }
    TreeNode* root = new TreeNode(mid->val);
    root->left = rec(head, mid);
    root->right = rec(mid->next, end);
    return root;
}
TreeNode* Solution::sortedListToBST(ListNode* head){
    if(!head) return NULL;
    if(!head->next) return new TreeNode(head->val);
    return rec(head, NULL);
}
