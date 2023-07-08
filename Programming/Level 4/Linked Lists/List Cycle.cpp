// Problem Name: List Cycle
// Problem Link: https://www.interviewbit.com/problems/list-cycle/

ListNode* Solution::detectCycle(ListNode* head){
    ListNode* s = head; ListNode* f = head;
    do{
        s = s->next;
        f = f->next->next;
    }while(s!=f and f and f->next);
    if(!f or !(f->next)) return NULL;
    s = head;
    while(s!=f){s=s->next; f=f->next;}
    return (s);
}
