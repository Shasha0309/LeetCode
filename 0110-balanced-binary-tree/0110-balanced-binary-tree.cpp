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
int solve(TreeNode* root){
    if(root==NULL) return 0;
    int res1 = solve(root->left);
    if(res1==-1) return -1;
    int res2 = solve(root->right);
    if(res2==-1) return -1;

    if(abs(res1-res2)>1) return -1;
    return 1+max(res1,res2);
}
    bool isBalanced(TreeNode* root) {
        return solve(root)!=-1;
    }
};