class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid;
        int ans = nums[0];
        int res;
        while(low<=high){
            mid = low+(high-low)/2;
            if(nums[mid]<ans){
                high = mid-1;
                res = nums[mid];
                ans = min(ans,res);
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};