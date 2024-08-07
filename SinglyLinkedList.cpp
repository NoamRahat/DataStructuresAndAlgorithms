#include <iostream>
#include <vector>

using namespace std;

class ListNode {
private:
    int value;
    ListNode* next;

public:
    ListNode(int value) {
        this->value = value;
        next = nullptr;
    }

    int getValue() {return this->value;}

    ListNode *getNext() {return this->next;}

    void setNext(ListNode *nextNode) {this->next = nextNode;}
};

class LinkedList {
private:
    ListNode* head;
    ListNode* tail;
    int size;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int getSize() {return size;}
    
    // LinkedList does not have a capacity like arrays.
    int getCapacity() {return size;}

    int get(int index) {
        if (!head || index < 0 || index >= size)
            return -1;

        int i = 0;
        ListNode* curr = head;
  
        while(curr){
            if (i == index)
                return curr->getValue();

            curr = curr->getNext();
            i++;
        }

        return -1;
    }

    void insertHead(int val) {
        ListNode *newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->setNext(head);
            head = newNode;
        }
        size++;
    }

    void insertTail(int val) {
        ListNode* newNode = new ListNode(val);
        if(!tail) {
            head = newNode;
            tail = newNode;
        } else {
            tail->setNext(newNode);
            tail = newNode;
        }
        size++;
    }

    bool remove(int index) {
        if (!head || index < 0 || index >= size)
            return false;

        ListNode* curr = head;
        ListNode* prev = nullptr;

        //Remove head
        if (index == 0) {
            head = head->getNext();
            if (!head)
                tail = nullptr;  // List becomes empty
            delete curr;
            size--;
            return true;
        }

        for (int i = 0; i < index; i++) {
            prev = curr;
            curr = curr->getNext();
        }

        prev->setNext(curr->getNext());
        if (index == size - 1) // If removing the last element
            tail = prev;

        delete curr;
        size--;
        return true;
    }

    vector<int> getValues() {
        vector<int> vec;
        if (!head)
            return vec;
        
        ListNode* curr = head;
        while (curr != nullptr){
            vec.push_back(curr->getValue());
            curr = curr->getNext();
        }
        return vec;
    }
};

// Unit test function for LinkedList
void testLinkedList() {
    cout << "Running tests for LinkedList..." << endl;

    LinkedList list;

    // Test insertHead and getValues
    list.insertHead(1);
    list.insertHead(2);
    list.insertHead(3);
    vector<int> values = list.getValues();
    cout << "List values after inserting 3, 2, 1 at head: ";
    for (int val : values) {
        cout << val << " ";
    }
    cout << endl;

    // Test insertTail
    list.insertTail(4);
    list.insertTail(5);
    values = list.getValues();
    cout << "List values after inserting 4, 5 at tail: ";
    for (int val : values) {
        cout << val << " ";
    }
    cout << endl;

    // Test get
    cout << "Element at index 2: " << list.get(2) << endl;

    // Test remove
    list.remove(1);
    values = list.getValues();
    cout << "List values after removing element at index 1: ";
    for (int val : values) {
        cout << val << " ";
    }
    cout << endl;

    // Test remove head
    list.remove(0);
    values = list.getValues();
    cout << "List values after removing element at index 0: ";
    for (int val : values) {
        cout << val << " ";
    }
    cout << endl;

    // Test getSize
    cout << "List size: " << list.getSize() << endl;

    cout << "All tests completed successfully." << endl;
}
