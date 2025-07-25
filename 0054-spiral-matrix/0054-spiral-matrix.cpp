class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int srow = 0;
        int erow = n-1;
        int scol = 0;
        int ecol = m-1;
        int tot = n*m;
        int nis=0;
        while(nis<tot){
            for(int i=scol;i<=ecol && nis<tot;i++){
                ans.push_back(matrix[srow][i]);
                nis++;
            }
             srow++;
              for(int i=srow;i<=erow && nis<tot;i++){
                ans.push_back(matrix[i][ecol]);
                nis++;
            }
             ecol--;
              for(int i=ecol;i>=scol && nis<tot;i--){
                ans.push_back(matrix[erow][i]);
                nis++;
            }
             erow--;
              for(int i=erow;i>=srow && nis<tot;i--){
                ans.push_back(matrix[i][scol]);
                nis++;
            }
             scol++;
        }
        return ans;  
    }
};