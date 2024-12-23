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
    TreeNode* solve(vector<int>& A,int& i,int valu){
        if(i==A.size() || A[i]>valu) return NULL;
        TreeNode* node = new TreeNode(A[i++]);
        node->left = solve(A,i,node->val);
        node->right = solve(A,i,valu);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(preorder,i,INT_MAX);
    }
};