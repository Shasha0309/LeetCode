class Solution {
    int toFind(vector<vector<int>> mat,int mid,int n,int m){
        int index = -1;
        int maxelement = -1;
        for(int i=0;i<n;i++){
            if(mat[i][mid]>maxelement){
                maxelement = mat[i][mid];
                index = i;
            }
        }
        return index;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m-1;
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            int maxele = toFind(mat,mid,n,m);
            int left = mid-1>=0 ? mat[maxele][mid-1] : -1;
            int right = mid+1<m ? mat[maxele][mid+1] : -1;
            if(mat[maxele][mid]>left && mat[maxele][mid]>right){
                return {maxele,mid};
            } 
            else if(mat[maxele][mid]>left){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
       }
       return {-1,-1};
    }
};