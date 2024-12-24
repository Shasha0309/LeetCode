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
    void solve(TreeNode* root,vector<int>& ans){
        if(!root) return;
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }

    void check(TreeNode* root,vector<int>& ans,int& i ){
        if(!root) return;
        check(root->left,ans,i);
        if(root->val!=ans[i]) root->val=ans[i];
        i++;
        check(root->right,ans,i);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        sort(ans.begin(),ans.end());
        int i=0;
        check(root,ans,i);
    }
};