class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size();
        int mid;
        while(l<=h){
            mid = l+(h-l)/2;
            if(nums[mid]==target) return true;
            if(nums[l]==nums[mid] && nums[mid]==nums[h]){
                l++;
                h--;
                continue;
            }
            
            else if(nums[mid]>=nums[l]){
                if(nums[l]<=target && target<=nums[mid]) h=mid-1;
                else l=mid+1;
            }
            else{
                if(target>=nums[mid] && target<=nums[h]) l=mid+1;
                else h=mid-1;
            }
        }
        return false;
    }
};