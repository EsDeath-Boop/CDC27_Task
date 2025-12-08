#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class Solution {
    public:
        void deleteNode(ListNode* node) {
            node->val = node->next->val;
            node->next = node->next->next;
        }
    };

    return 0;
}