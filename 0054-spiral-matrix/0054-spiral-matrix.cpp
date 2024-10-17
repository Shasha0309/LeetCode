class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int total = n*m;
        int cnt = 0;
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = m-1;
        vector<int> ans;
        while(cnt<total){
           for(int i=left;i<=right && cnt<total;i++){
            ans.push_back(matrix[top][i]);
            cnt++;
           }
           top++;
           for(int i=top;i<=bottom && cnt<total;i++){
            ans.push_back(matrix[i][right]);
            cnt++;
           }
           right--;
           for(int i=right;i>=left && cnt<total;i--){
            ans.push_back(matrix[bottom][i]);
            cnt++;
           }
           bottom--;
           for(int i=bottom;i>=top && cnt<total;i--){
            ans.push_back(matrix[i][left]);
            cnt++;
           }
           left++;
        }
        return ans;
    }
};