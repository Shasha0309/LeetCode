class Solution {
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& board,int drow[],int dcol[],int n,int m){
        vis[i][j]=1;
        for(int s=0;s<4;s++){
            int r = i+drow[s];
            int c = j+dcol[s];
            if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && board[r][c]=='O'){
                dfs(r,c,vis,board,drow,dcol,n,m);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int drow[4] = {1,0,-1,0};
        int dcol[4] = {0,1,0,-1};
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(0,i,vis,board,drow,dcol,n,m);
            }
            if(!vis[n-1][i] && board[n-1][i]=='O'){
                dfs(n-1,i,vis,board,drow,dcol,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(0,i,vis,board,drow,dcol,n,m);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(m-1,i,vis,board,drow,dcol,n,m);
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