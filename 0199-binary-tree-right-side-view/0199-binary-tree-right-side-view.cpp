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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            int n = st.size();
            int res;
            for(int i=0;i<n;i++){
            TreeNode* sroot = st.front();
            res=sroot->val;
            st.pop();
            if(sroot->left!=NULL) st.push(sroot->left);
            if(sroot->right!=NULL) st.push(sroot->right);
            //res.push_back(sroot->val);
        }
        ans.push_back(res);
        }
        return ans;
    }
};