class Solution {
    void dfs(int i,int j,vector<vector<int>>& vis,int n,int m,vector<vector<int>>& grid,int drow[],int dcol[]){
        vis[i][j]=1;
        for(int s=0;s<4;s++){
            int r = i+drow[s];
            int c = j+dcol[s];
            if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && grid[r][c]==1) dfs(r,c,vis,n,m,grid,drow,dcol);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
       // queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int drow[4] = {0,1,0,-1};
        int dcol[4] = {1,0,-1,0};
        for(int i=0;i<m;i++){
           if(!vis[0][i] && grid[0][i]==1){
            dfs(0,i,vis,n,m,grid,drow,dcol);
           }
           if(!vis[n-1][i] && grid[n-1][i]==1){
            dfs(n-1,i,vis,n,m,grid,drow,dcol);
           }
        }
        for(int i=0;i<n;i++){
           if(!vis[i][0] && grid[i][0]==1){
            dfs(i,0,vis,n,m,grid,drow,dcol);
           }
           if(!vis[i][m-1] && grid[i][m-1]==1){
            dfs(i,m-1,vis,n,m,grid,drow,dcol);
           }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
};