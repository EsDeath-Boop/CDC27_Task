class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
int diameterRecur(Node* root, int &res) {
  
    if (root == nullptr)
        return 0;

    int lHeight = diameterRecur(root->left, res);
    int rHeight = diameterRecur(root->right, res);
    

    res = max(res, lHeight+rHeight);
    return 1 + max(lHeight, rHeight);
}

int diameter(Node* root) {
  
    int res = 0;
    diameterRecur(root, res);
    return res;
}