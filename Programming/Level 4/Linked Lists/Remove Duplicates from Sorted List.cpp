// Problem Name: Remove Duplicates from Sorted List
// Problem Link: https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

ListNode* Solution::deleteDuplicates(ListNode* head){
    if(!head or !(head->next)) return head;
    ListNode* i = head; ListNode* j = head->next;
    while(j){
        if(j->val == i->val) j = j->next;
        else{
            i->next = j;
            i = j;
            j = j->next;
        }
    }
    i->next = NULL;
    return head;
}
