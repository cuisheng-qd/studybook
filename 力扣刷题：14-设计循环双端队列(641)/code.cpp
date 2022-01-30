class MyCircularDeque {
private:
    vector<int> data;
    int head, tail, size, count;
public:
    MyCircularDeque(int k):
        data(k),
        size(k),
        head(0),
        tail(0),
        count(0) {

    }
    
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        count++;
        if (head == 0) {
            head = size - 1;
        } else {
            head--;
        }
        data[head] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        count++;
        data[tail] = value;
        if (tail < size - 1) {
            tail++;
        } else {
            tail = 0;
        }
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        count--;
        if (head < size - 1) {
            head++;
        } else {
            head = 0;
        }
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        count--;
        if (tail == 0) {
            tail = size - 1;
        } else {
            tail--;
        }
        return true;
    }
    
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return data[head];
    }
    
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        if (tail == 0) {
            return data[size - 1];
        } else {
            return data[tail - 1];
        }
    }
    
    bool isEmpty() {
        return this->count == 0;
    }
    
    bool isFull() {
        return this->count == this->size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
