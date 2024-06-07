class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int top_row = 0;
        int right_col = n-1;
        int bottom_row = m-1;
        int left_col = 0;
        int count = 0;
        vector<int> ans;
        while(count<m*n){
            for(int i=left_col;i<=right_col && count<m*n;i++){
            ans.push_back(matrix[top_row][i]);
            count++;
        }
        top_row++;
        
        for(int i=top_row;i<=bottom_row && count<m*n;i++){
            ans.push_back(matrix[i][right_col]);
            count++;
        }
        right_col--;

         for(int i=right_col;i>=left_col && count<m*n;i--){
            ans.push_back(matrix[bottom_row][i]);
            count++;
        }
        bottom_row--;

         for(int i=bottom_row;i>=top_row && count<m*n;i--){
            ans.push_back(matrix[i][left_col]);
            count++;
        }
        left_col++;
        }
        return ans;
    }
};