#include <iostream>
#include <new> // for std::nothrow

using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

public:
    // Constructor to initialize the dynamic array with a given capacity
    DynamicArray(int capacity) : capacity(capacity), size(0) {
        arr = new (nothrow) int[capacity];
        if (!arr) {
            cout << "Memory allocation failed\n";
        }
    }

    // Destructor to release allocated memory
    ~DynamicArray() {
        delete[] arr;
    }

    // Will return the element at index i. Assume that index i is valid.
    int get(int i) {
        return arr[i];
    }

    // Will set the element at index i to n. Assume that index i is valid.
    void set(int i, int n) {
        arr[i] = n;
    }

    // Will push the element n to the end of the array.
    void pushback(int n) {
        if (size == capacity) {
            resize();
        }
        arr[size] = n;
        size++;
    }

    // Will pop and return the element at the end of the array. Assume that the array is non-empty.
    int popback() {
        size--;
        return arr[size];
    }

    // Resizes the array when capacity is reached.
    void resize() {
        capacity *= 2;
        int* newArr = new (nothrow) int[capacity];
        if (!newArr) {
            cout << "Resize memory allocation failed\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    // Returns the current size of the array.
    int getSize() {
        return size;
    }

    // Returns the current capacity of the array.
    int getCapacity() {
        return capacity;
    }
};

// Unit test function for DynamicArray
void testDynamicArray() {
    cout << "Running tests for DynamicArray..." << endl;

    DynamicArray arr(5);

    // Test pushback and get
    arr.pushback(1);
    arr.pushback(2);
    arr.pushback(3);
    arr.pushback(4);
    arr.pushback(5);
    
    for (int i = 0; i < arr.getSize(); i++) {
        cout << "Element at index " << i << ": " << arr.get(i) << endl;
    }

    // Test resizing
    arr.pushback(6);
    cout << "After resizing, array capacity: " << arr.getCapacity() << endl;

    for (int i = 0; i < arr.getSize(); i++) {
        cout << "Element at index " << i << ": " << arr.get(i) << endl;
    }

    // Test popback
    cout << "Popped element: " << arr.popback() << endl;
    cout << "After popping, array size: " << arr.getSize() << endl;

    for (int i = 0; i < arr.getSize(); i++) {
        cout << "Element at index " << i << ": " << arr.get(i) << endl;
    }

    // Test set
    arr.set(0, 10);
    cout << "After setting index 0 to 10, element at index 0: " << arr.get(0) << endl;

    cout << "All tests completed successfully." << endl;
}
