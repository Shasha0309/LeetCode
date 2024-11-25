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
    int solve(TreeNode* root){
        return root==NULL ? 0:(1+max(solve(root->left),solve(root->right)));
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int node1 = solve(root->left);
        int node2 = solve(root->right);
        if((abs(node2-node1)<=1) && isBalanced(root->left) && isBalanced(root->right)) return true;
        return false;
    }
};