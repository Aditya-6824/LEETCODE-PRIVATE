
class Solution {
public:
    bool isBSTUtil(TreeNode* node, long long min, long long max) {
        if (node == nullptr) 
            return true;

        if (node->val <= min || node->val >= max) 
            return false;

        return isBSTUtil(node->left, min, node->val) &&
               isBSTUtil(node->right, node->val, max);
    }

    bool isValidBST(TreeNode* root) {
        // Use long long limits to avoid overflow issues
        return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
    }
};