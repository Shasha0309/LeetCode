/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            
                TreeNode* node = q.front();
                q.pop();
                if(node==NULL) ans.append("#,");
                else ans.append(to_string(node->val)+',');
                if(node!=NULL) {q.push(node->left);
             q.push(node->right);}
            
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#"){
                node->left=NULL;
            }
            else{
                TreeNode* root = new TreeNode(stoi(str));
                node->left = root;
                q.push(root); 
            }
             getline(s,str,',');
            if(str=="#"){
                node->right=NULL;
            }
            else{
                TreeNode* root = new TreeNode(stoi(str));
                node->right = root;
                q.push(root); 
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));