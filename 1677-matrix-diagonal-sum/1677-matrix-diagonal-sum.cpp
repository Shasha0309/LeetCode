class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int i=0;
        int j=m-1;
        int sum = 0;
        while(i<n && j>=0){
            sum+=mat[i][i];
            if(i!=j){
                sum+=mat[i][j];
            }
            i++;
            j--;
        }
        return sum;
    }
};