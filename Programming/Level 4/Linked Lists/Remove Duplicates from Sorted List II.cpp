// Problem Name: Remove Duplicates from Sorted List II
// Problem Link: https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/

ListNode* Solution::deleteDuplicates(ListNode* head){
    if(!head or !(head->next)) return head;
    ListNode* curr = head; ListNode* temp;
    ListNode* newHead = NULL; ListNode* prev = NULL;
    while(curr){
        if(curr->next){
            if(curr->val != curr->next->val){
                if(!newHead) newHead = curr;
                prev = curr;
                curr = curr->next;
                continue;
            }else{
                temp = curr->next;
                while(temp and curr->val == temp->val) temp = temp->next;
                if(!prev) prev = temp;
                else prev->next = temp;
                if(!temp) break;
                curr = temp;
            }
        }else break;
    }
    return newHead;
}
