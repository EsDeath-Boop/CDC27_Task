#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if(head == NULL || head->next==NULL)    return head;
            ListNode* tail = NULL;
            ListNode* temp = head;
            int len = 0;
            while(temp!=NULL){
                if(temp->next==NULL)    tail = temp;
                len++;
                temp = temp->next;
            }
            temp = head;
            k = k % len;
            if(k==0)    return head;
            int idx = len-k;
            for(int i = 1;i<idx;i++){
                temp = temp->next;
            }
            tail->next = head;
            head = temp->next;
            temp->next = NULL;
            return head;
        }
    };
    return 0;
}