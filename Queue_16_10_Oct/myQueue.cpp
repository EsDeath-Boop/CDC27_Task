#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class myQueue {
    private:
        int* arr;        // Array to store elements
        int frontIndex;  // Index of front element
        int rearIndex;   // Index of rear element
        int size;        // Current number of elements
        int capacity;    // Maximum capacity of the queue

    public:
        // Constructor
        myQueue(int n) {
            capacity = n;
            arr = new int[n];
            frontIndex = 0;
            rearIndex = -1;
            size = 0;
        }

        // Check if the queue is empty
        bool isEmpty() {
            return size == 0;
        }

        // Check if the queue is full
        bool isFull() {
            return size == capacity;
        }

        // Add an element at the rear
        void enqueue(int x) {
            if (isFull()) return;            // Do nothing if full
            rearIndex = (rearIndex + 1) % capacity;
            arr[rearIndex] = x;
            size++;
        }

        // Remove the front element
        void dequeue() {
            if (isEmpty()) return;           // Do nothing if empty
            frontIndex = (frontIndex + 1) % capacity;
            size--;
        }

        // Get the front element
        int getFront() {
            if (isEmpty()) return -1;
            return arr[frontIndex];
        }

        // Get the rear element
        int getRear() {
            if (isEmpty()) return -1;
            return arr[rearIndex];
        }

        // Destructor to free memory
        ~myQueue() {
            delete[] arr;
        }
    };

    return 0;
}