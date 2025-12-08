#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
            ListNode* tempA = a;
            ListNode* tempB = b;
            ListNode* c = new ListNode(10);
            ListNode* temp = c;
            int x,y,carry = 0;
            while(tempA || tempB) {
                if(tempA)   x = tempA -> val;
                else x = 0;
                if(tempB)   y = tempB -> val;
                else y = 0;
                int sum = x + y + carry;
                carry = sum / 10;
                temp -> next = new ListNode(sum % 10);
                temp = temp -> next;
                if(tempA)   tempA = tempA -> next;
                if(tempB)   tempB = tempB -> next; 
                cout<<"Hello"<<endl;
            }
            if(carry)   temp -> next = new ListNode(carry);
            return c -> next;
        }
    };
    return 0;
}