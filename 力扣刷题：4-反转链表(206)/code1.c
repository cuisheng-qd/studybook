/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* tail = head;
    while (tail->next != NULL) {
        struct ListNode* current = tail->next;
        tail->next = current->next;
        current->next = head;
        head = current;
    }
    return head;
}
