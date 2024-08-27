class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid;
        int ans1 = -1;
        int ans2 = -1;
        while(low<=high){
            mid = low+(high-low)/2;
            if(nums[mid]<target){
                low=mid+1;
            }
            else{ 
                high = mid-1;
                if(nums[mid]==target){
                ans1 = mid;
            }
            }
        }
        low = 0;
         high = n-1;
         while(low<=high){
            mid = low+(high-low)/2;
            if(nums[mid]>target){ 
                high = mid-1;
            }
            else{
                low=mid+1;
                if(nums[mid]==target){
                ans2 = mid;
            }
            }   
        }
        return {ans1,ans2};
    }
};