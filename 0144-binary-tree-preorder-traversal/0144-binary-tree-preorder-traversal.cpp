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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            int n = st.size();
            for(int i=0;i<n;i++){
                TreeNode* nef = st.top();
                st.pop();
                ans.push_back(nef->val);
                if(nef->right!=NULL) st.push(nef->right);
                if(nef->left!=NULL) st.push(nef->left);
            }
        }
        return ans;
    }
};