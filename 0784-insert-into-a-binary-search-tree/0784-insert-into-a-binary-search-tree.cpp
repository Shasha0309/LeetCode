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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(root==NULL) return node;
        TreeNode* root1=root;
        while(root1!=NULL){
            if(root1->val<val){
               if(root1->right!=NULL) root1=root1->right;
               else{
                
                root1->right=node;
                break;
               }
            }
            else{
                 if(root1->left!=NULL) root1=root1->left;
               else{
                
                root1->left=node;
                break;
               }
            }
        }
        return root;
    }
};