/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* __reverseN(struct ListNode* head, int n) {
    if (n == 1) {
        return head;
    }
    struct ListNode* tail = head->next;
    struct ListNode* p = __reverseN(head->next, n - 1);
    head->next = tail->next;
    tail->next = head;
    return p;
}

struct ListNode* reverseN(struct ListNode* head, int n) {
    struct ListNode* p = head;
    int cnt = n;
    while (--cnt && p) {
        p = p->next;
    }
    if (p == NULL) {
        return head;
    }
    return __reverseN(head, n);
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode ret = {
        .val = 0,
        .next = head
    };
    struct ListNode* prev = &ret;
    struct ListNode* next = prev->next;
    while ((prev->next = reverseN(next, k)) != next) {
        prev = next;
        next = prev->next;
    }
    return ret.next;
}
