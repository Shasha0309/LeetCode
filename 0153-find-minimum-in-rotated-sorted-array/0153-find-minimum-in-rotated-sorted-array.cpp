class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid;
        int ans = nums[0];
        int res;
        if(nums[n-1]>nums[0]) return nums[0];
        while(low<=high){
            mid = low+(high-low)/2;
            if(nums[mid]>nums[high]){
                res = nums[mid];
                low = mid+1;
                ans = min(ans,res);
            }
            else{
                high = mid-1;
                res=nums[mid];
                ans = min(ans,res);
            }
        }
        return ans;
    }
};