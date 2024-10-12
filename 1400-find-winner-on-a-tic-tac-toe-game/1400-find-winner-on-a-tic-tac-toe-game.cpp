class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> board(3,vector<int>(3,0));
        for(int i=0;i<moves.size();i++){
            int tris = (i%2==0) ? 1 : 2; 
            board[moves[i][0]][moves[i][1]] = tris;
        }
        
        for(int i=0;i<3;i++){
            if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=0){ return (board[i][0]==1) ? "A" : "B";
            } 
            if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=0){
                return (board[0][i]==1) ? "A" : "B";
            }
        }
            if((board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=0) || (board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=0)){
                return (board[1][1]==1) ? "A" : "B";
            }
        if(moves.size()==9) return "Draw";
        return "Pending";
    }
};