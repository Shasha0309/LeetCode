class Solution {
    void dfs(int inicolor,vector<vector<int>>& adj,int color,int sr,int sc,int row[],int col[],vector<vector<int>>& image){
        int n = image.size();
        int m = image[0].size();
        adj[sr][sc] = color;
        for(int i=0;i<4;i++){
            int newrow = sr+row[i];
            int newcol = sc+col[i];
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && image[newrow][newcol]==inicolor && adj[newrow][newcol]!=color){
                dfs(inicolor,adj,color,newrow,newcol,row,col,image);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        vector<vector<int>> adj = image;
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};
        dfs(inicolor,adj,color,sr,sc,drow,dcol,image);
        return adj;
    }
};