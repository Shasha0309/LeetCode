class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int low=0;
        int high=(r*c)-1;
        int mid;
        while(low<=high){
            mid = low+(high-low)/2;
            int ind = matrix[mid/c][mid%c];
            if(ind==target) return true;
            else if(ind>target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};