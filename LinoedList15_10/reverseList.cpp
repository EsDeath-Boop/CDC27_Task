#include <bits/stdc++.h>
using namespace std;


 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* nex = head;
            while(curr != NULL) {
                nex = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = nex;
            }
            return prev;
        }
    };
    return 0;
}