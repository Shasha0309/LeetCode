//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    void solve(Node* root,map<Node*,Node*>& mpp){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr->left){
                mpp[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                mpp[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    Node* tar(Node* root,int target){
        if(root==NULL) return NULL;
        if(root->data==target){
            return root;
            }
        //if(root==NULL) return NULL;
        Node* lefti =  tar(root->left,target);
        if(lefti!=NULL) return lefti;
        Node* righti = tar(root->right,target);
        if(righti!=NULL) return righti;
        return NULL;
    }
  public:
    int minTime(Node* root, int target) {
        // code here
        map<Node*,Node*> mpp;
        solve(root,mpp);
        
        queue<Node*> q;
        int t=0;
        Node* curr=tar(root,target);
        q.push(curr);
        unordered_map<Node*,bool> visited;
        visited[curr] = 1;
        while(!q.empty()){
            int n = q.size();
            int f=0;
            for(int i=0;i<n;i++){
                Node* node = q.front();
            q.pop();
            if(node->left && !visited[node->left]){
                f=1;
                q.push(node->left);
                visited[node->left]=1;
            }
            if(node->right && !visited[node->right]){
                q.push(node->right);
                visited[node->right]=1;
                f=1;
            }
            if(mpp[node] && !visited[mpp[node]]){
                q.push(mpp[node]);
                visited[mpp[node]]=1;
                f=1;
            }
        }
        if(f==1) t++;
        }
        return t;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends