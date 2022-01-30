/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* p = head;
    struct ListNode* q = head->next;
    while (n--) {
        if (q == NULL) {
            return p->next;
        }
        q = q->next;
    }
    while (q != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = p->next->next;
    return head;
}
