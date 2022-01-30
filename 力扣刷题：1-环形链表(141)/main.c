/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
        if (fast == NULL) {
            return false;
        }
        fast = fast->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}
