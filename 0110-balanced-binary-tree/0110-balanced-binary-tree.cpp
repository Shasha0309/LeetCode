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
    int solve(TreeNode* node){
        if(node==NULL) return 0;
        int lefti = solve(node->left);
        if(lefti==-1) return -1;
        int righti = solve(node->right);
        if(righti==-1) return -1;
        if (abs(lefti-righti)>1) return -1;
        return max(lefti,righti)+1;
    } 
public:
    bool isBalanced(TreeNode* root) {
        return solve(root)!=-1;
    }
};