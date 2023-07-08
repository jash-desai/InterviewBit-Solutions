// Problem Name: Palindrome List
// Problem Link: https://www.interviewbit.com/problems/palindrome-list/

/*
int Solution::lPalin(ListNode* head){
    ListNode* curr = head; vector<int> v;
    while(curr){
        v.push_back(curr->val);
        curr = curr->next;
    }
    return (v == vector<int>(rbegin(v), rend(v)));
}
*/
ListNode* rev(ListNode* head){
    if(!(head->next)) return head;
    ListNode* prev = NULL; ListNode* curr = head;
    ListNode* nxt = head->next;
    while(nxt){
        curr->next = prev;
        prev = curr;
        curr = nxt;
        nxt = curr->next;
    }
    curr->next = prev;
    return curr;
}
int Solution::lPalin(ListNode* head){
    if(!(head->next)) return 1;
    ListNode* slow = head; ListNode* fast = head;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* newHead;
    if(fast) newHead = rev(slow->next);
    else newHead = rev(slow);
    ListNode* i = head;
    ListNode* j = newHead;
    while(j){
        if(i->val != j->val) return 0;
        i=i->next; j=j->next;
    }
    return 1;
}
