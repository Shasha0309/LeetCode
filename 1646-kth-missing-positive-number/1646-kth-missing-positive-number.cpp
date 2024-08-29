class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int mid;
        while(low<=high){
            mid = low+(high-low)/2;
            int missy = arr[mid]-(mid+1);
            if(missy<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high+k+1;
    }
};