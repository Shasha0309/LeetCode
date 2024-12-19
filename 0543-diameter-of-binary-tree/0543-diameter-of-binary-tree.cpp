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
    int solve(TreeNode* node,int& cnt){
        if(node==NULL) return 0;
        int lefti = solve(node->left,cnt);
        int righti = solve(node->right,cnt);
        cnt = max(cnt,lefti+righti);
        return max(lefti,righti)+1;

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int cnt = 0;
         solve(root,cnt);
         return cnt;
    }
};