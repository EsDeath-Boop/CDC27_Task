#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class MyLinkedList {
    private:
        struct Node {
            int val;
            Node* next;
            Node(int x) : val(x), next(nullptr) {}
        };

        Node* head;   // first node
        int size;     // number of nodes

    public:
        MyLinkedList() {
            head = nullptr;
            size = 0;
        }
        
        int get(int index) {
            if (index < 0 || index >= size) return -1;
            Node* cur = head;
            while (index--) {
                cur = cur->next;
            }
            return cur->val;
        }
        
        void addAtHead(int val) {
            Node* node = new Node(val);
            node->next = head;
            head = node;
            size++;
        }
        
        void addAtTail(int val) {
            Node* node = new Node(val);
            if (!head) {
                head = node;
            } else {
                Node* cur = head;
                while (cur->next) cur = cur->next;
                cur->next = node;
            }
            size++;
        }
        
        void addAtIndex(int index, int val) {
            if (index < 0 || index > size) return;

            if (index == 0) {
                addAtHead(val);
                return;
            }

            Node* cur = head;
            for (int i = 0; i < index - 1; i++) {
                cur = cur->next;
            }

            Node* node = new Node(val);
            node->next = cur->next;
            cur->next = node;
            size++;
        }
        
        void deleteAtIndex(int index) {
            if (index < 0 || index >= size) return;

            if (index == 0) {
                Node* temp = head;
                head = head->next;
                delete temp;
            } else {
                Node* cur = head;
                for (int i = 0; i < index - 1; i++) {
                    cur = cur->next;
                }
                Node* temp = cur->next;
                cur->next = temp->next;
                delete temp;
            }
            size--;
        }
    };


    return 0;
}