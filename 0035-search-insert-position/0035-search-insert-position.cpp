class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]<target){
                
                //ans = mid;
                //if(mid==n-1) return ans;
                low = mid+1;
            }
            else if(nums[mid]>target){
              //if(ans==-1) ans = mid;
             // if(high == 0) ans=high;
               high = mid-1;
            }
            else{
                return mid;
            }
        }
        return low;
    }
};