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
    int solve(TreeNode* root,int& sum){
        if(root==NULL) return 0;
        int node1=max(0,solve(root->left,sum));
        int node2=max(0,solve(root->right,sum));
        sum=max(sum,node1+node2+root->val);
        return max(node1,node2)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int sum=INT_MIN;
        solve(root,sum);
        return sum;
    }
};