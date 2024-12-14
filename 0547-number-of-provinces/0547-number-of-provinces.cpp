class Solution {
    void solve(int node,vector<int> dp[],vector<int>& vis){
        vis[node]=1;
        for(auto it:dp[node])
        if(!vis[it]){
            solve(it,dp,vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adj[V];

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(V,0);
        int cnt=0;
        for(int i=0;i<V;i++){
            
            if(!vis[i]){
                cnt++;
                solve(i,adj,vis);
            }
        }
        return cnt;
         
    }
};