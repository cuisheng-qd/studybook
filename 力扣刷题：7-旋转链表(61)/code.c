/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k){
    if (head == NULL) {
        return head;
    }
    int n = 1;
    struct ListNode* p = head;
    while (p->next) {
        p = p->next;
        n++;
    }
    k %= n;
    n -= k;
    p->next = head;
    while (n--) {
        p = p->next;
    }
    head = p->next;
    p->next = NULL;
    return head;
}
