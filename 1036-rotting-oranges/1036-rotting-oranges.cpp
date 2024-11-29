class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j]==1) cnt++;
            }
        }
        int tm = 0;
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};
        int cfrt = 0;
        while(!q.empty()){
           int r = q.front().first.first;
           int c = q.front().first.second;
           int tis = q.front().second;
           q.pop();
           tm=max(tm,tis);
           for(int i=0;i<4;i++){
            int rrow=drow[i]+r;
            int ccol=dcol[i]+c;
            if(rrow>=0 && rrow<n && ccol>=0 && ccol<m && grid[rrow][ccol]==1 && vis[rrow][ccol]!=2){
                q.push({{rrow,ccol},tis+1});
                vis[rrow][ccol]=2;
                cfrt++;
            }
           }
        }
        if(cfrt!=cnt) return -1;
        return tm;
    }
};