class MyCircularQueue {
private:
    vector<int> data; // 数据
    int capacity; // 容量
    int head; // 队头索引
    int tail; // 队尾索引加1
    int size; // 当前队列大小
public:
    MyCircularQueue(int k): 
        data(k), 
        capacity(k),
        head(0),
        tail(0),
        size(0) {
    }
    
    bool enQueue(int value) {
        if (this->isFull()) {
            return false;
        }
        this->size ++;
        
        this->data[this->tail] = value;
        if (this->tail < this->capacity - 1) {
            this->tail ++;
        } else {
            this->tail = 0;
        }
        return true;
    }
    
    bool deQueue() {
        if (this->isEmpty()) {
            return false;
        }
        this->size --;
        if (this->head < this->capacity - 1) {
            this->head ++;
        } else {
            this->head = 0;
        }
        return true;
    }
    
    int Front() {
        if (this->size == 0) {
            return -1;
        }
        return this->data[this->head];
    }
    
    int Rear() {
        if (this->size == 0) {
            return -1;
        }
        if (this->tail == 0) {
            return this->data[this->capacity - 1];
        } else {
            return this->data[this->tail - 1];
        }
    }
    
    bool isEmpty() {
        return this->size == 0;
    }
    
    bool isFull() {
        return this->size == this->capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */