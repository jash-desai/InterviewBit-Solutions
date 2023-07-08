// Problem Name: Reverse Linked List
// Problem Link: https://www.interviewbit.com/problems/reverse-linked-list/

ListNode* Solution::reverseList(ListNode* head) {
    if((head->next) == NULL) return head;
    /*
    ListNode* newHead = reverseList(head->next);
    ListNode* curr = newHead;
    while(curr->next != NULL) curr = curr->next;
    curr->next = head;
    head->next = NULL;
    return newHead;
    */
    ListNode* curr = head; ListNode* prev = NULL;
    ListNode* nxtt = head->next;
    while(nxtt){
        curr->next = prev;
        prev = curr;
        curr = nxtt;
        nxtt = curr->next;
    }
    curr->next = prev;
    return curr;
}
