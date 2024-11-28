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
    bool solve(long long min,long long max,TreeNode* root){
        if(root==NULL) return true;
        if(root->val<=min || root->val>=max) return false;
        return ((solve(min,root->val,root->left)) && solve(root->val,max,root->right));
    }
public:
    bool isValidBST(TreeNode* root) {
        long long min = -100000000;
        long long max = 1000000000;
        if(root->left==NULL && root->right==NULL) return false;
        return solve(min,max,root);
    }
};