// Problem Name: Rotate List
// Problem Link: https://www.interviewbit.com/problems/rotate-list/

ListNode* Solution::rotateRight(ListNode* head, int k){
    if(!head or !(head->next) or !k) return head;
    ListNode* curr = head; int n = 1;
    while(curr->next){ n++; curr = curr->next;}
    k = k%n; if(k==0) return head; k = (n-k-1);
    curr->next = head; curr = head; 
    while(k--) curr = curr->next;
    ListNode* ans = curr->next; curr->next = NULL;
    return ans;
}
