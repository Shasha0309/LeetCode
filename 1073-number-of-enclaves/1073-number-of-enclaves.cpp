class Solution {
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& mat,int dr[],int dc[],int n,int m){
        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int r = row+dr[i];
            int c = col+dc[i];
            if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && mat[r][c]==1){
                dfs(r,c,vis,mat,dr,dc,n,m);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
         int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(!vis[0][i] && grid[0][i]==1){
                dfs(0,i,vis,grid,drow,dcol,n,m);
            }
            if(!vis[n-1][i] && grid[n-1][i]==1){
                dfs(n-1,i,vis,grid,drow,dcol,n,m);
            }
        }
        for(int j=0;j<n;j++){
            if(!vis[j][0] && grid[j][0]==1){
                dfs(j,0,vis,grid,drow,dcol,n,m);
            }
            if(!vis[j][m-1] && grid[j][m-1]==1){
                dfs(j,m-1,vis,grid,drow,dcol,n,m);
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};