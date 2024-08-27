class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        int ans = 0;
        if(target<nums[0]) return 0;
        while(low<=high){
            mid = low+(high-low)/2;
            if(nums[mid]<target){
                ans = mid;
                low = mid+1;
            }
            else if(nums[mid]>target){
                high = mid-1;
        }
            else{
                return mid;
            }
        }
        return ans+1;
    }
};