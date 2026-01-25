class Solution {
public:
    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> trees;

        // Base case
        if (start > end) {
            trees.push_back(NULL);
            return trees;
        }

        // Try each number as root
        for (int i = start; i <= end; i++) {
            // All left subtrees
            vector<TreeNode*> leftTrees = build(start, i - 1);
            // All right subtrees
            vector<TreeNode*> rightTrees = build(i + 1, end);

            // Combine left & right
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }

        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }
};