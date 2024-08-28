class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        if(n==1) return 0;
        int mid; 
        while(low<=high){
            mid = low + (high-low)/2;
            if(mid+1<n && mid-1>=0 && nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){return mid;}
            else if(mid+1<n && nums[mid]<nums[mid+1]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return nums[0]>nums[1] && nums[n-1]<nums[0] ? 0 : n-1;
    }
};