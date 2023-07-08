// Problem Name: Add Two Numbers as Lists
// Problem Link: https://www.interviewbit.com/problems/add-two-numbers-as-lists/

ListNode* Solution::addTwoNumbers(ListNode* a, ListNode* b){
    if(!a or !b) return a ? a : b;
    int c = 0, sum = 0;
    sum = a->val + b->val + c;
    ListNode* curr = new ListNode(sum%10);
    c = sum/10; a = a->next; b = b->next;
    ListNode* ans = curr;
    while(a or b or c){
        sum = (a ? a->val : 0) + (b ? b->val : 0) + c;
        ListNode* temp = new ListNode(sum%10);
        c = sum/10; curr->next = temp; curr = curr->next;
        if(a) a = a->next;
        if(b) b = b->next;
    }
    return ans;
}
