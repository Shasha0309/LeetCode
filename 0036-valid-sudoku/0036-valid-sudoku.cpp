class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> row[9];
        unordered_set<int> col[9];
        unordered_set<int> box[9];

        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]=='.') continue;
                char val = board[r][c];
                int box_ind = (r/3)*3 + (c/3);
                if(row[r].count(val) || col[c].count(val) || box[box_ind].count(val)) return false;

               row[r].insert(val);
               col[c].insert(val);
               box[box_ind].insert(val); 
            }
        }
        return true;
    }
};