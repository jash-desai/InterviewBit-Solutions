// Problem Name: Reorder List
// Problem Link: https://www.interviewbit.com/problems/reorder-list/

ListNode* rev(ListNode* head){
    if(!head or !(head->next)) return head;
    ListNode* curr = head, *prev = NULL, *nxt = NULL;
    while(curr){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
ListNode* Solution::reorderList(ListNode* head){
    if(!head or !(head->next)) return head;
    int n = 0; ListNode* curr = head;
    while(curr){ n++; curr = curr->next; }
    curr = head; int t = (n>>1);
    if(n%2){
        while(t--) curr = curr->next;
        ListNode* newCurr = (curr->next); curr->next = NULL;
        curr = head; newCurr = rev(newCurr);
        ListNode* currNext = curr->next, *newNext = newCurr->next;
        while(curr){
            curr->next = newCurr;
            curr = currNext; 
            if(!curr) break;
            newCurr->next = curr;
            newCurr = newNext;
            currNext = curr->next;
            if(newNext) newNext = newCurr->next;
        }
        return head;
    }else{
        t--;
        while(t--) curr = curr->next;
        ListNode* newCurr = (curr->next); curr->next = NULL;
        curr = head; newCurr = rev(newCurr);
        ListNode* currNext = curr->next, *newNext = newCurr->next;
        while(newCurr){
            curr->next = newCurr;
            curr = currNext; 
            newCurr->next = curr;
            newCurr = newNext;
            if(!newCurr) break;
            currNext = curr->next;
            newNext = newCurr->next;
        }
        return head;
    }
}