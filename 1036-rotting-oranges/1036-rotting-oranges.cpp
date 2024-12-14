class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
          vector<vector<int>> vis(n,vector<int>(m,0));
        int total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                if(grid[i][j]==1){
                    total++;
                }
            }
        }
        int cnt = 0;
        int tm = 0;
      
        int ro[] = {1,0,-1,0};
        int co[] = {0,1,0,-1};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int tis = q.front().second;
            q.pop();
            tm = max(tm,tis);
            for(int i=0;i<4;i++){
                int drow = ro[i]+x;
                int dcol = co[i]+y;
                if(drow>=0 && drow<n && dcol>=0 && dcol<m && grid[drow][dcol]==1 && vis[drow][dcol]!=2){
                    vis[drow][dcol] = 2;
                    q.push({{drow,dcol},tis+1});
                    cnt++;
                }
            }
        }
        if(cnt!=total) return -1;
        return tm;
    }
};