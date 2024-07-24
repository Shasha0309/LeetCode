class Solution {
     int solve1(vector<int> &nums){
          int prev2 = 0;
          int prev = nums[0];
         for(int i=1;i<nums.size();i++){
            int pick = nums[i];
            if(i>1) pick += prev2;
            int notpick = prev;
            int curr = max(pick,notpick);
        
        prev2 = prev;
        prev = curr;
         }
         return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> nums1, nums2;
       for(int i=0;i<n;i++){
        if(i!=n-1) nums1.push_back(nums[i]);
        if(i!=0) nums2.push_back(nums[i]);
       }
       return max(solve1(nums1),solve1(nums2));
    }
};