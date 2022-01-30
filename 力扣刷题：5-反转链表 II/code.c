/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 翻转N个节点
struct ListNode* reverseN(struct ListNode* head, int n) {
    if (n == 1) {
        return head;
    }
    
    struct ListNode* next = head->next;
    struct ListNode* curr = reverseN(next, n - 1);
    head->next = next->next;
    next->next = head;
    return curr;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode prevObject = {
        .val = 0,
        .next = head
    };
    struct ListNode* prev = &prevObject;
    head = prev;
    for (int i = 1; i < left; i++) {
        head = head->next;
    }
    head->next = reverseN(head->next, right - left + 1);
    return prev->next;
}
