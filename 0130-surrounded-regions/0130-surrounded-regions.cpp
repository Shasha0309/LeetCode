class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i]=='O'){
                q.push({0,i});
            }
            if(!vis[n-1][i] && board[n-1][i]=='O'){
                q.push({n-1,i});
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                q.push({i,0});
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                q.push({i,m-1});
            }
        }
        int drow[4] = {0,1,0,-1};
        int dcol[4] = {1,0,-1,0};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            vis[r][c]=1;
            for(int i=0;i<4;i++){
                int rr = r+drow[i];
                int cc = c+dcol[i];
                if(rr>=0 && rr<n && cc>=0 && cc<m && !vis[rr][cc] && board[rr][cc]=='O'){
                    vis[rr][cc]=1;
                    q.push({rr,cc});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};