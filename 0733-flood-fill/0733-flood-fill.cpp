class Solution {
    void sol(int precol,vector<vector<int>>& ans,int sr,int sc,int drow[], int dcol[],int color,vector<vector<int>> image){
        int n = image.size();
        int m = image[0].size();
        ans[sr][sc]=color;
        for(int i=0;i<4;i++){
            int r = sr+drow[i];
            int c = sc+dcol[i];
            if(r>=0 && r<n && c>=0 && c<m && image[r][c]==precol && ans[r][c]!=color){
               // ans[r][c] = color;
                sol(precol,ans,r,c,drow,dcol,color,image);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       // int n = image.size();
       // int m = image[0].size();
        vector<vector<int>> ans = image;
       int drow[4] = {0,1,0,-1};
       int dcol[4] = {1,0,-1,0};
       int prevcol = image[sr][sc];
       sol(prevcol,ans,sr,sc,drow,dcol,color,image);
       return ans;
    }
};