/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapTwo(struct ListNode* first, struct ListNode* second) {
    first->next = second->next;
    second->next = first;
    return second;
}

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode ret = {
        .val = 0,
        .next = head
    }, *p = &ret, *q;
    while (p && p->next && p->next->next) {
        q = p->next->next;
        p->next = swapTwo(p->next, q);
        p = q->next;
    }
    return ret.next;
}
