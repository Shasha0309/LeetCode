class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> adj(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
       // int total = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                   vis[i][j]=1;
                   q.push({{i,j},0});
                }
               /* else{
                    total++;
                }*/
            }
        }
        int drow[4]={0,1,0,-1};
        int dcol[4]={1,0,-1,0};
        //int t=1;
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int tis = q.front().second;
            q.pop();
            adj[i][j]=tis;
            for(int s=0;s<4;s++){
                int r = i+drow[s];
                int c = j+dcol[s];
                if(r>=0 && r<n && c>=0 && c<m && vis[r][c]==0 && mat[r][c]==1){
                    vis[r][c]=1;
                    q.push({{r,c},tis+1});
                    
                }
            }
        }
        return adj;
    }
};