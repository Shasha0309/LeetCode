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
    void solve(TreeNode* root,int k,int& cnt,int& ans ){
         if(!root || cnt>=k) return;
         solve(root->left,k,cnt,ans);
         cnt++;
         if(cnt==k){
            ans=root->val;
             return;
         }
         solve(root->right,k,cnt,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ans = -1;
        solve(root,k,cnt,ans);
        return ans;
    }
};