/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    struct LinkedList {
        int val;
        LinkedList *next;
        LinkedList(int val): val(val), next(nullptr) {}
        LinkedList(int val, LinkedList *next): val(val), next(next) {}
    };

    MyLinkedList() {
        this->_dummy = new LinkedList(0);
        this->_size = 0;
    }
    
    int get(int index) {
        if (((index+1) > this->_size) || (index < 0)) {
            return -1;
        }
        LinkedList *temp = this->_dummy;
        for (int i = index; i >= 0; i--) {
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        LinkedList *temp = new LinkedList(val, this->_dummy->next);
        this->_dummy->next = temp;
        this->_size++;
    }
    
    void addAtTail(int val) {
        LinkedList *temp = this->_dummy;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new LinkedList(val);
        this->_size++;
    }
    
    void addAtIndex(int index, int val) {
        LinkedList *temp = this->_dummy;
        if (index == this->_size) {
            addAtTail(val);
            return;
        }
        if ((index+1) > this->_size) {
            return;
        }
        if (index <= 0) {
            addAtHead(val);
        }
        else {
            for (int i = index; i > 0; i--) {
                temp = temp->next;
            }
            temp->next = new LinkedList(val, temp->next);
            this->_size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (((index+1) > this->_size) || (index < 0)) {
            return;
        }
        LinkedList *temp = this->_dummy;
        LinkedList *temp_del;
        for (int i = index; i > 0; i--) {
            temp = temp->next;
        }
        temp_del = temp->next;
        temp->next = temp->next->next;
        delete temp_del;
        this->_size--;
    }
private:
    int _size;
    LinkedList* _dummy;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

