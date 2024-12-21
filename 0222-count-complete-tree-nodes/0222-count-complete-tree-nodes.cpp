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
    bool leaf(TreeNode* root){
        return !root->left && !root->right;
    }
    int heightl(TreeNode* root){
        int cnt=0;
        while(root){
            cnt++;
            root=root->left;
        }
        return cnt;
    }
    int heightr(TreeNode* root){
        int cnt=0;
        while(root){
            cnt++;
            root=root->right;
        }
        return cnt;
    }
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lefth = heightl(root);
        int righth = heightr(root);
        if(lefth==righth) return (1 << lefth)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};