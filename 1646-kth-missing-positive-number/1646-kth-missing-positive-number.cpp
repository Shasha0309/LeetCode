class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int mid;
        int missing;
        while(low<=high){
            mid=low+(high-low)/2;
            missing=arr[mid]-(mid+1);
            if(missing<k) low=mid+1;
            else high=mid-1;
        }
        //int tre = arr[high]-(high+1);
        //int res = k-tre;
        //int ans = arr[high]+res;
        return low+k;
    }
};