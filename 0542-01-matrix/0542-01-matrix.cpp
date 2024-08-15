class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            ans[r][c] = t;
            for(int i=0;i<4;i++){
                int newr = r+drow[i];
                int newc = c+dcol[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m && vis[newr][newc]==0){
                    vis[newr][newc] = 1;
                    q.push({{newr,newc},t+1});
                }
            }
        }
        return ans;
    }
};