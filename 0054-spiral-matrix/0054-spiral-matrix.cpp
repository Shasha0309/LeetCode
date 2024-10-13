class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = m-1;
        int total = n*m;
        int cnt = 0;
        vector<int> ans;
        while(cnt<total){
            for(int i=left;cnt<total && i<=right;i++){
               ans.push_back(matrix[top][i]);
               cnt++;
            }
            top++;
            for(int i=top;cnt<total && i<=bottom;i++){
                ans.push_back(matrix[i][right]);
                cnt++;
            }
            right--;
            for(int i=right;cnt<total && i>=left;i--){
                ans.push_back(matrix[bottom][i]);
                cnt++;
            }
            bottom--;
            for(int i=bottom;cnt<total && i>=top;i--){
                ans.push_back(matrix[i][left]);
                cnt++;
            }
            left++;
        }
        return ans;
    }
};