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
        if(root==NULL) return 0;
        int res1 = solve(root->left);
        int res2 = solve(root->right);
        return 1+max(res1,res2);

    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int max1 = solve(root->left);
        int max2 = solve(root->right);
        if((abs(max1-max2)<=1) && isBalanced(root->left) && isBalanced(root->right)) return true;
        return false;
    }
};