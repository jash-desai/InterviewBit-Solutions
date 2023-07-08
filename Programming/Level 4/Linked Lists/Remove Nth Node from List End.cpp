// Problem Name: Remove Nth Node from List End
// Problem Link: https://www.interviewbit.com/problems/remove-nth-node-from-list-end/

ListNode* Solution::removeNthFromEnd(ListNode* head, int k){
    int n = 0; ListNode* curr = head;
    if(!(head->next) and k!=0) return NULL;
    while(curr){ n++; curr = curr->next; }
    if(k>=n){ head = head->next; return head; }
    ListNode* slow = head; ListNode* fast = head;
    for(int i=0; i<k; i++) fast = fast->next;
    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}
