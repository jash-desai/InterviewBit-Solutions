// Problem Name: Partition List
// Problem Link: https://www.interviewbit.com/problems/partition-list/

ListNode* Solution::partition(ListNode* head, int k){
    if(!head or !(head->next)) return head;
    ListNode* curr = head;
    ListNode* head1 = NULL, *prev1 = NULL;
    ListNode* head2 = NULL, *prev2 = NULL;
    while(curr){
        if(curr->val < k){
            if(!head1){
                head1 = new ListNode(curr->val);
                prev1 = head1;
            }else{
                prev1 -> next = new ListNode(curr->val);
                prev1 = prev1 -> next;
            }
        }else{
            if(!head2){
                head2 = new ListNode(curr->val);
                prev2 = head2;
            }else{
                prev2 -> next = new ListNode(curr->val);
                prev2 = prev2 -> next;
            }
        }
        ListNode* temp = curr;
        curr = curr->next; free(temp);
    }
    if(!head1) return head2;
    prev1 -> next = head2;
    return head1;
}
