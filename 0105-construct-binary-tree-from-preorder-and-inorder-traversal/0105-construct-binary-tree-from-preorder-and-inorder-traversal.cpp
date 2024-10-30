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
    TreeNode* solve(vector<int>& preorder,int prestr,int preend,vector<int>& inorder,int instr,int inend,map<int,int>& mpp){
        if(prestr>preend || instr>inend) return NULL;
        TreeNode* root = new TreeNode(preorder[prestr]);
        int inroot = mpp[root->val];
        int subroot = inroot-instr;

        root->left = solve(preorder,prestr+1,prestr+subroot,inorder,instr,inroot-1,mpp);
        root->right = solve(preorder,prestr+subroot+1,preend,inorder,inroot+1,inend,mpp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mpp;
        int n = inorder.size();
        for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root = solve(preorder,0,preorder.size()-1,inorder,0,n-1,mpp);
        return root;
    }
};