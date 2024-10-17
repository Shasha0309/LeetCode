class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                    swap(matrix[i][j],matrix[j][i]);
            }
        }
       int i=0;
       int j=m-1;
       int k=0;
       while(k<n && i<=j){
          swap(matrix[k][i],matrix[k][j]);
          k++;
          if(k==n){
            k=0;
            i++;
            j--;
          }
       }
    }
};