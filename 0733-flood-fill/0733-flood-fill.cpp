class Solution {
    void solve(int incolor,vector<vector<int>>& adj,int drow[],int dcol[],int sr,int sc,int color,vector<vector<int>>& img){
        int n = img.size();
        int m = img[0].size();
        adj[sr][sc]=color;
        for(int i=0;i<4;i++){
             int row = sr+drow[i];
             int col = sc+dcol[i];
             if(row>=0 && row<n && col>=0 && col<m && img[row][col]==incolor && adj[row][col]!=color){
                solve(incolor,adj,drow,dcol,row,col,color,img);
             }
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int incolor = image[sr][sc];
        vector<vector<int>> adj = image;
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};
        solve(incolor,adj,drow,dcol,sr,sc,color,image);
        return adj;
    }
};