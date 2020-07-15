/**
* 52/52 Test cases passed
* Runtime: 52 ms (Beats 61.09% of cpp submissions)
* Memory Usage: 16.8 MB (Beats 43.21% of cpp submissions)
*/

class MyCircularQueue {
private:
    vector<int> queue;
    int size;
    int front;
    int rear;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        for(int i = 0; i < k; i++) {
            this->queue.push_back(-1);
        }
        this->size = k;
        this->front = -1;
        this->rear = -1;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        if(isEmpty()) {
            this->front = 0;
        } else if(this->rear + 1 > this->size - 1) {
            this->rear = -1;
        }
        this->rear++;
        this->queue[this->rear] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        if(this->front == this->rear) {
            this->front = -1;
            this->rear = -1;
            return true;
        } else if(this->front + 1 > this->size -1) {
            this->front = -1;
        }
        this->front++;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) {
            return -1;
        }
        return this->queue[this->front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) {
            return -1;
        }
        return this->queue[this->rear];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(this->front == -1 && this->rear == -1) {
            return true;
        }
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if((this->front - 1) == this->rear || (this->front == 0 && this->rear == this->size - 1)) {
            return true;
        }
        return false;
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