class Solution {
    void dfs(vector<vector<int>>& vis,vector<vector<int>>& grid,int r,int c,int n,int m){
        vis[r][c]=1;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int rr = drow[i]+r;
            int cc = dcol[i]+c;
            if(rr>=0 && rr<n && cc>=0 && cc<m && grid[rr][cc]==1 && !vis[rr][cc]){
                dfs(vis,grid,rr,cc,n,m);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<m;i++){
            if(grid[0][i]==1 && !vis[0][i]){
                dfs(vis,grid,0,i,n,m);
            }
            if(grid[n-1][i]==1 && !vis[n-1][i]){
                dfs(vis,grid,n-1,i,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(vis,grid,i,0,n,m);
            }
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                dfs(vis,grid,i,m-1,n,m);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};