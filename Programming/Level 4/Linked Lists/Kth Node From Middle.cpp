// Problem Name: Kth Node From Middle
// Problem Link: https://www.interviewbit.com/problems/kth-node-from-middle/

int Solution::solve(ListNode* head, int k){
    if(head->next == NULL and k>0) return -1;
    ListNode* s = head; ListNode* f = head; ListNode* mid;
    while(f and f->next){ s = s->next; f = f->next->next; }
    mid = s; bool flag = 0; f = head; s = head;
    for(int i=0; i<k; i++){
        f = f->next;
        if(f==mid and i!=k-1) flag = 1;
    }
    if(flag) return -1;
    while(f!=mid){ s = s->next; f = f->next; }
    return (s->val);
}
