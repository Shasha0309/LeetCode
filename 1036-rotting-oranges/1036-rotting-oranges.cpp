class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cntfr = 0;
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1) cntfr++;
            }
        }
        int tm = 0;
        int derow[] = {1,0,-1,0};
        int decol[] = {0,1,0,-1};
        int cnt=0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm,t);
            for(int i=0;i<4;i++){
                int srow = r + derow[i];
                int scol = c + decol[i];
                if(srow>=0 && srow<n && scol>=0 && scol<m && grid[srow][scol]==1 && vis[srow][scol]!=2){
                    q.push({{srow,scol},t+1});
                    vis[srow][scol] = 2;
                    cnt++;
                } 
            }
        }
        if(cntfr!=cnt) return -1;
        return tm;
    }
};