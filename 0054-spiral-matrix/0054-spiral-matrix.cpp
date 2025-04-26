class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int total = n*m;
        int cnt = 0;
        int srow = 0;
        int erow = n-1;
        int scol = 0;
        int ecol = m-1; 
        while(cnt<total){
            for(int i=scol;i<=ecol && cnt<total;i++){
                ans.push_back(matrix[srow][i]);
                cnt++;
            }
            srow++;
            for(int i=srow;i<=erow && cnt<total;i++){
                ans.push_back(matrix[i][ecol]);
                cnt++;
            }
            ecol--;
            for(int i=ecol;i>=scol && cnt<total;i--){
                ans.push_back(matrix[erow][i]);
                cnt++;
            }
            erow--;
            for(int i=erow;i>=srow && cnt<total;i--){
                ans.push_back(matrix[i][scol]);
                cnt++;
            }
            scol++;
        }
        return ans;
    }
};