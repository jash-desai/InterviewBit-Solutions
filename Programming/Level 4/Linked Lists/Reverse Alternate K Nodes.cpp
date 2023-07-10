// Problem Name: Reverse Alternate K Nodes
// Problem Link: https://www.interviewbit.com/problems/reverse-alternate-k-nodes/

ListNode* Solution::solve(ListNode* head, int k){
    if(!head or !(head->next) or k==1) return head;
    ListNode* curr = head, *newHead = head, *prevTail = NULL;
    for(int i=0; i<k-1; i++) newHead = newHead->next;
    while(curr){
        int t{0}; ListNode* prev = NULL, *nxt = NULL;
        ListNode* prevHead = curr;
        while(t<k){
            if(t==k-1 and prevTail) prevTail->next = curr;
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            t++;
        }
        prevHead->next = curr;
        while(t-- and curr){
            if(t==0) prevTail = curr;
            curr = curr->next;
            if(!curr) break;
        }
    }
    return newHead;
}
