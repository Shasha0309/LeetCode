class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        int str = 0;
        int lst = n-1;
        while(str<lst){
            for(int i=0;i<n;i++){
            swap(matrix[i][str],matrix[i][lst]);
            }
            str++;
            lst--;
        }
    }
};