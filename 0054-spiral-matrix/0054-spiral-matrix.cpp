class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int rmin = 0;
        int rmax = matrix.size()-1;
        int cmin = 0;
        int cmax = matrix[0].size()-1;
        int count = 0;
        vector<int> ans;
        while(count<m*n){
            //top
            for(int i=cmin;i<=cmax && count<m*n;i++){
                 ans.push_back(matrix[rmin][i]);
                count++;
            }
            rmin++;

            //extreme right
            for(int i=rmin;i<=rmax && count<m*n;i++){
                ans.push_back(matrix[i][cmax]);
                count++;
            }  
            cmax--;

            //extreme bottom
             
            for(int i=cmax;i>=cmin && count<m*n;i--){
                ans.push_back(matrix[rmax][i]);
                count++;
            }
        
            rmax--;

            //extreme left
            
            for(int i=rmax;i>=rmin && count<m*n;i--){
                ans.push_back(matrix[i][cmin]);
                count++;
            }
            
            cmin++;
        }
    
    return ans;
}
};