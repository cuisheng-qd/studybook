/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* newNode() {
    struct Node* ret = (struct Node*)malloc(sizeof(struct Node));
    ret->val = 0;
    ret->next = NULL;
    ret->random = NULL;
    return ret;
}

int countNodeIndex(struct Node* target, struct Node* head) {
    if (target == NULL) {
        return -1;
    }
    int index = -1;
    while (head) {
        index ++;
        if (target == head) {
            return index;
        }
        head = head->next;
    }
    return index;
}

int indexNode(int index, struct Node* head) {
    while (index-- && head) {
        head = head->next;
    }
    return head;
}

struct Node* copyRandomList(struct Node* head) {
	if (head == NULL) {
        return NULL;
    }
    struct Node* ret = newNode();
    struct Node* o = head; // 源链表指针
    struct Node* n = ret; // 新链表指针
    int count = 0;
    do {
        count ++;
        // 生成链表，维护好next指针，random留空
        n->next = newNode();
        n = n->next;
        n->val = o->val;
        o = o->next;
    } while (o);

    // 处理random指针
    o = head;
    n = ret->next;
    int randomTo;
    for (int i = 0; i < count; i++) {
        randomTo = countNodeIndex(o->random, head);
        n->random = indexNode(randomTo, ret->next);
        o = o->next;
        n = n->next;
    }

    return ret->next;
}
