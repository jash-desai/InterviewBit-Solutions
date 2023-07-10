// Problem Name: Reverse Link List II
// Problem Link: https://www.interviewbit.com/problems/reverse-link-list-ii/

ListNode* Solution::reverseBetween(ListNode* head, int a, int b){
    if(!head or !(head->next) or a==b) return head;
    ListNode* prevTail = NULL, *curr = head, *prevHead = NULL;
    ListNode* newHead = NULL;
    for(int i=0; i<a-1; i++){
        if(i==0) newHead = curr;
        if(i==a-2) prevTail = curr;
        curr = curr->next;
    }prevHead = curr; int t{b-a+1};
    ListNode* prev = NULL, *nxt = NULL;
    while(t--){
        if(t==0 and !newHead) newHead = curr;
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    prevHead->next = curr;
    if(!prevTail) return newHead;
    prevTail->next = prev;
    return newHead;
}