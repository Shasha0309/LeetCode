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
    bool solve(TreeNode* root,TreeNode* sub){
        if(root==NULL || sub==NULL) return root==sub;
        return (root->val==sub->val && solve(root->left,sub->left) && solve(root->right,sub->right));
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL) return true;
        if(root==NULL) return false;
        if(solve(root,subRoot)) return true;
        
            return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        
    }
};