class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       // vector<int> ans = {-1,-1};
        int low = 0;
        int high = nums.size()-1;
        
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                int i = mid;
                int j=mid;
                while(i>0 && nums[i-1]==nums[i]) i--;
                while(j<nums.size()-1 && nums[j+1]==nums[j]) j++;
                return {i,j};
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};