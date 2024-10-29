/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int solve(TreeNode* root,int maxVal) {
        if (root == NULL) return 0;
        
        // Check if current node is a "good node"
        int good = root->val >= maxVal ? 1 : 0;

        // Update maxVal for the path to children
        maxVal = std::max(maxVal, root->val);

        // Recursively count good nodes in the left and right subtrees
        good += solve(root->left, maxVal);
        good += solve(root->right, maxVal);
        
        return good;
    }
public:
    int goodNodes(TreeNode* root) {
        return solve(root,INT_MIN);
    }
};