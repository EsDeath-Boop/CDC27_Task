#include <bits/stdc++.h>
using namespace std;
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution {
  public:
    bool isHeap(Node* tree) {
        // code here
        queue<Node*>q;
        q.push(tree);
        bool hasNullChild = false;
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if(curr -> left) {
                if(hasNullChild || curr->data < curr -> left -> data) {
                    return false;
                }
                q.push(curr->left);
            } else {
                hasNullChild = true;
            }
            if(curr -> right) {
                if(hasNullChild || curr->data < curr -> right -> data) {
                    return false;
                }
                q.push(curr->right);
            } else {
                hasNullChild = true;
            }
        }
        return true;
    }
};