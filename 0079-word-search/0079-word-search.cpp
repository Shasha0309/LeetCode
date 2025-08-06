class Solution {
    bool sol(int i,int j,int ind,string& word,vector<vector<char>>& board,vector<vector<bool>>& vis){
        int n = board.size();
        int m = board[0].size();
        
         
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || board[i][j]!=word[ind]) return false;
        if(ind==word.length()-1) return true;
        vis[i][j]=1;
        
          bool found = sol(i+1,j,ind+1,word,board,vis) ||
                       sol(i-1,j,ind+1,word,board,vis) ||
                       sol(i,j-1,ind+1,word,board,vis) ||
                       sol(i,j+1,ind+1,word,board,vis);
        
        vis[i][j]=0;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
      
        int n = board.size();
        int m = board[0].size();
          vector<vector<bool>> path(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(sol(i,j,0,word,board,path)) return true;
            }
        }
        return false;
    }
};