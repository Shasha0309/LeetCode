class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid;
        int ans1=-1;
        int ans2=-1;
         while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
            if (nums[mid] == target) {
                ans1 = mid;
            }
        }
    }
    
    // Find the last occurrence of the target
    low=0;
    high=n-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
            if (nums[mid] == target) {
                ans2 = mid;
            }
        }
    }
        /*if(n==0){
            return {ans1,ans1};
        }
        //vector<int> ans;
        while(low<=high){
            mid = low+(high-low)/2;
            if(nums[mid]<target){
                low = mid+1;
            }
            else if(nums[mid]>target){
                high = mid-1;
                
            }
            else{
                ans1=mid;
                ans2 = mid+1;
                break;
            }
        }*/
        //if(ans1!=-1) ans2 = ans1++;
        return {ans1,ans2};
    }
};