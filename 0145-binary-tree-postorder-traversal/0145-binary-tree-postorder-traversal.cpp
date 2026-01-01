
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;

        while (curr || !st.empty()) {
            if (curr) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* node = st.top();
                if (node->right && lastVisited != node->right) {
                    curr = node->right;
                } else {
                    res.push_back(node->val);
                    lastVisited = node;
                    st.pop();
                }
            }
        }
        return res;
    }
};