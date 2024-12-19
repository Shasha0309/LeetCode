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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            vector<int> level;
            int n = st.size();
            for(int i=0;i<n;i++){
                TreeNode* node = st.front();
                st.pop();  
                if(node->left!=NULL) st.push(node->left);
                if(node->right!=NULL) st.push(node->right);
                 level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};