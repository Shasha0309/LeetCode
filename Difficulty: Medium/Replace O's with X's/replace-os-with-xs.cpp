//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& mat,int dr[],int dc[],int n,int m){
        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int r = row+dr[i];
            int c = col+dc[i];
            if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && mat[r][c]=='O'){
                dfs(r,c,vis,mat,dr,dc,n,m);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(!vis[0][i] && mat[0][i]=='O'){
                dfs(0,i,vis,mat,drow,dcol,n,m);
            }
            if(!vis[n-1][i] && mat[n-1][i]=='O'){
                dfs(n-1,i,vis,mat,drow,dcol,n,m);
            }
        }
        for(int j=0;j<n;j++){
            if(!vis[j][0] && mat[j][0]=='O'){
                dfs(j,0,vis,mat,drow,dcol,n,m);
            }
            if(!vis[j][m-1] && mat[j][m-1]=='O'){
                dfs(j,m-1,vis,mat,drow,dcol,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]=='O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends