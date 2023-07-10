// Problem Name: Even Reverse
// Problem Link: https://www.interviewbit.com/problems/even-reverse/

/* O(N/2) - Extra Space 
ListNode* Solution::solve(ListNode* head){
    if(!head or !(head->next)) return head;
    if(!(head->next->next) or !(head->next->next->next)) return head;
    ListNode* a = head->next; vector<int> v = {a->val}; a = a->next->next;
    while(a){
        v.push_back(a->val);
        if(a->next) a = a->next->next;
        else break;
    }
    a = head->next; int i = size(v)-1;
    while(a){
        a->val = v[i--];
        if(a->next) a = a->next->next;
        else break;
    }
    return head;
}
*/
/* O(1) - Extra Space */
ListNode* rev(ListNode* head){
    if(!head or !(head->next)) return head;
    ListNode* prev = NULL, *nxt = NULL, *curr = head;
    while(curr){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
ListNode* Solution::solve(ListNode* head){
    if(!head or !(head->next)) return head;
    if(!(head->next->next) or !(head->next->next->next)) return head;
    ListNode* a = head; ListNode* b = head->next; ListNode* evenHead = head->next;
    while(a and b){
        a->next = b->next; a = a->next;
        if(a) b->next = a->next;
        else b->next = NULL; 
        b = b->next;
    }
    if(a) a->next = NULL;
    if(b) b->next = NULL;
    a = head; b = rev(evenHead); 
    ListNode* aNext = a->next, *bNext = b->next;
    while(a and b){
        a->next = b; a = aNext;
        b->next = a; b = bNext;
        if(!a and !b) break;
        if(a) aNext = a->next;
        if(b) bNext = b->next;
    }
    return head;
}