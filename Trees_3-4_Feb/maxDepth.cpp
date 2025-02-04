class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return std::max(leftDepth, rightDepth) + 1;
    }
};

TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode();
    node->val = val;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}