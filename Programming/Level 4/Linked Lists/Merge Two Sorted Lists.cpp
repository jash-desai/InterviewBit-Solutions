// Problem Name: Merge Two Sorted Lists
// Problem Link: https://www.interviewbit.com/problems/merge-two-sorted-lists/

ListNode* Solution::mergeTwoLists(ListNode* a, ListNode* b){
    ListNode* i = a; ListNode* j = b;
    if(a->val > b->val) swap(a,b);
    while(i and j){
        if(i->val <= j->val){
            while(i->next and i->next->val <= j->val) i = i->next;
            ListNode* temp = i->next;
            i->next = j;
            i = temp;
        }else{
            while(j->next and j->next->val <= i->val) j = j->next;
            ListNode* temp = j->next;
            j->next = i;
            j = temp;
        }
    }
    return a;
}
