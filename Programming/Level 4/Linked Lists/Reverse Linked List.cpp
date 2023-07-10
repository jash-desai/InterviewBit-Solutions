// Problem Name: Reverse Linked List
// Problem Link: https://www.interviewbit.com/problems/reverse-linked-list/

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
ListNode* Solution::reverseList(ListNode* head) {
    if(!head or !(head->next)) return head;
    return rev(head);
}

