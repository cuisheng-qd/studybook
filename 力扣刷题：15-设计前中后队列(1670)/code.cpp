class Node {
public:
    int val;
    Node* prev;
    Node* next;

    Node(int _val = 0): val(_val), prev(nullptr), next(nullptr) {}

    void insert_before(Node* node) {
        node->prev = prev;
        node->next = this;
        prev->next = node;
        prev = node;
    }
    void insert_after(Node* node) {
        node->next = next;
        node->prev = this;
        next->prev = node;
        next = node;
    }
    void remove_self() {
        if (prev) {
            prev->next = next;
        }
        if (next) {
            next->prev = prev;
        }
    }
};

class Queue {
private:
    Node head;
    Node tail;
public:
    int length;
    Queue(): length(0) {
        head.next = &tail;
        tail.prev = &head;
    }
    void add_front(int val) {
        Node* node = new Node(val);
        head.next->insert_before(node);
        length++;
    }
    void add_back(int val) {
        Node* node = new Node(val);
        tail.prev->insert_after(node);
        length++;
    }
    int pop_front() {
        if (length == 0) {
            return -1;
        }
        length --;
        Node *node = head.next;
        int ret = node->val;
        node->remove_self();
        delete node;
        return ret;
    }
    int pop_back() {
        if (length == 0) {
            return -1;
        }
        length --;
        Node *node = tail.prev;
        int ret = node->val;
        node->remove_self();
        delete node;
        return ret;
    }
    void output() {
        Node *node = head.next;
        while (node->next) {
            cout << "  " << node->val;
            node = node->next;
        }
        cout << endl;
    }
};

class FrontMiddleBackQueue {
private:
    Queue q1;
    Queue q2;
    void update() {
        if (q2.length > q1.length + 1) {
            q1.add_back(q2.pop_front());
        } else if (q1.length > q2.length) {
            q2.add_front(q1.pop_back());
        }
        // cout << "------- begin -------" << endl;
        // q1.output();
        // q2.output();
        // cout << "------- end -------" << endl;
    }
public:
    FrontMiddleBackQueue() {
    }
    
    void pushFront(int val) {
        q1.add_front(val);
        update();
    }
    
    void pushMiddle(int val) {
        q2.add_front(val);
        update();
    }
    
    void pushBack(int val) {
        q2.add_back(val);
        update();
    }
    
    int popFront() {
        int ret;
        if (q1.length == 0) {
            ret = q2.pop_front();
        } else {
            ret = q1.pop_front();
        }
        update();
        return ret;
    }
    
    int popMiddle() {
        int ret;
        if (q1.length == q2.length) {
            ret = q1.pop_back();
        } else {
            ret = q2.pop_front();
        }
        update();
        return ret;
    }
    
    int popBack() {
        int ret = q2.pop_back();
        update();
        return ret;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
