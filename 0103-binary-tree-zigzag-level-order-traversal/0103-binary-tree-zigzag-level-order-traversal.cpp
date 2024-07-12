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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        bool lTor = true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
             vector<int> level(n);
            for(int i=0;i<n;i++){
                TreeNode* root = q.front();
                q.pop();
                int index = lTor ? i : (n-1-i);
                if(root->left != NULL) q.push(root->left);
                if(root->right != NULL) q.push(root->right);
                level[index] = root->val;
            }
            ans.push_back(level);
            lTor = !lTor;      
             }
        return ans;
    }
};