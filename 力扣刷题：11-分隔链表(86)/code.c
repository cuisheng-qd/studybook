/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode left = {
        .val = 0,
        .next = NULL
    }, right = {
        .val = 0,
        .next = NULL
    };
    struct ListNode *leftP = &left, *rightP = &right;

    while (head) {
        if (head->val < x) {
            leftP->next = head;
            leftP = head;
        } else {
            rightP->next = head;
            rightP = head;
        }
        head = head->next;
    }
    leftP->next = right.next;
    rightP->next = NULL;
    return left.next;
}
