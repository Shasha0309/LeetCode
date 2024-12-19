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
    int solve(TreeNode* node,int& ans){
        if(node==NULL) return 0;
        int lefti = max(0,solve(node->left,ans));
        int righti = max(0,solve(node->right,ans));
        ans = max(ans,lefti+righti+node->val);
        return max(lefti,righti)+node->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
    }
};