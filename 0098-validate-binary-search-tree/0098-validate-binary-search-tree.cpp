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
    private:
    bool isValid(TreeNode* root,long long minval, long long maxval){
        if(root==NULL) return true;
        if(root->val<=minval || root->val>=maxval) return false;
        return isValid(root->left,minval,root->val) && isValid(root->right,root->val,maxval);
    }
public:
    bool isValidBST(TreeNode* root) {
        long long int min = -1000000000000, max = 1000000000000;
         if(root->left==NULL && root->right==NULL) return true;
        return isValid(root,min,max);

    }
};