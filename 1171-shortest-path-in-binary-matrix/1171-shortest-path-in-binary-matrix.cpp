class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        queue<pair<pair<int,int>,int>> q;
      //  int cnt = 0;
        q.push({{0,0},1});
       // vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        dis[0][0]=1;
        while(!q.empty()){
            auto it = q.front();
            int dist=it.second;
            int r=it.first.first;
            int c=it.first.second;
            q.pop();
            if(r==n-1 && c==m-1) return dist;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(i==0 && j==0) continue;
                    int nr = r+i;
                    int nc = c+j;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0 && dist+1<dis[nr][nc]){
                        dis[nr][nc]=dist+1;
                        
                        q.push({{nr,nc},dist+1});
                    } 
                }
            }
        }
        return -1;
    }
};