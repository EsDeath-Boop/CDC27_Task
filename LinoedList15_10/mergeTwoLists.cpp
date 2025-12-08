#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
            ListNode* dummy = new ListNode(10);
            ListNode* temp = dummy;
            while(a && b) {
                if(a -> val <= b -> val) {
                    temp -> next = a;
                    a = a ->next;
                    temp = temp ->next;
                } else {
                    temp -> next = b;
                    b = b -> next;
                    temp = temp -> next;
                }
            }
            if(!a)  temp -> next = b;
            if(!b)  temp -> next = a;
            return dummy -> next;
        }
    };
    return 0;
}