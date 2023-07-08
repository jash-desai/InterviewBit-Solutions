// Problem Name: Sort Binary Linked List
// Problem Link: https://www.interviewbit.com/problems/sort-binary-linked-list/

ListNode* Solution::solve(ListNode* head){
    ListNode* r = head; ListNode* l = head;
    while(r){
        if(r->val == 0){
            swap(l->val, r->val);
            l = l->next; r = r->next;
        }else r = r->next;
    }
    return head;
}
