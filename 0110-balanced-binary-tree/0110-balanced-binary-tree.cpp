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
    int getheight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lhei = getheight(root->left);
        int rhei = getheight(root->right);

        return max(lhei,rhei)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int LH = getheight(root->left);
        int RH = getheight(root->right);

        if(abs(LH-RH)<=1 && isBalanced(root->left) && isBalanced(root->right)) return true;
        return false;
    }
};