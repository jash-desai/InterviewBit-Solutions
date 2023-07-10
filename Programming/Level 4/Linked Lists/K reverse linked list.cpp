// Problem Name: K reverse linked list
// Problem Link: https://www.interviewbit.com/problems/k-reverse-linked-list/

/* O(k) Extra Space 
ListNode* Solution::reverseList(ListNode* head, int k) {
    if(k==1 or !head) return head;
    ListNode* curr = head; vector<int> v(k); int i=0;
    while(i<k){
        v[i++] = curr->val;
        curr = curr->next;
    } curr = head; i=0;
    while(i<k){
        curr->val = v[k-i-1];
        curr = curr->next; i++;
    } reverseList(curr, k);
    return head;
}
*/

/* O(1) Extra Space */
ListNode* Solution::reverseList(ListNode* head, int k){
    if(k==1 or !head) return head; ListNode* curr = head;
    ListNode* newEnd = NULL; ListNode* newHead = head; int i=1;
    while(i++ < k) newHead = newHead->next;
    ListNode* first = curr;
    while(curr){
        int cnt = 0; ListNode* prev = NULL; ListNode* nxt = NULL;
        while(cnt<k){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            cnt++;
        }
        if(newEnd) newEnd->next = prev;
        newEnd = first;
        first = curr;
    }
    return newHead;
}