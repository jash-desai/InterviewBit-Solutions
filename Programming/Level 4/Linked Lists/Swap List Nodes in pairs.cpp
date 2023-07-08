// Problem Name: Swap List Nodes in pairs
// Problem Link: https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/

/* Recursive - 
ListNode* Solution::swapPairs(ListNode* head) {
    if(!head or !head->next) return head;
    ListNode* a = head; ListNode* b = head->next;
    a->next = swapPairs(b->next); b->next = a;
    return b;
}
*/

ListNode* Solution::swapPairs(ListNode* head) {
    if(!head or !head->next) return head;
    ListNode* a = head; ListNode* b = head->next;
    while(a and b){
        swap(a->val, b->val);
        a = b->next; if(!a) break;
        b = a->next;
    }
    return head;
}
