#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class Solution {
    public:
        ListNode* middleNode(ListNode* head) {
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast!=NULL && fast->next!=NULL){
                fast = fast->next->next;
                slow = slow->next;
            }
            return slow;
        }
    };
    return 0;
}