/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode result(0);
        searchLast(&result, head, k);
        return result.next ? result.next->val : head->val;
    }
    int searchLast(ListNode* result, ListNode* curr, int k) {
        if (curr->next == nullptr) {
            return 1;
        }
        curr = curr->next;
        int num = searchLast(result, curr, k);
        if (k == num) {
            result->next = curr;
        }
        return num + 1;
    }
};
