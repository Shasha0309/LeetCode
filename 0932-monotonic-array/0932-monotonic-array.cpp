class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        int carr = 0;
        if(nums[0]>nums[n-1]) carr =1;
        for(int i=0;i<n-1;i++){
            if(carr==1){
                if(nums[i]<nums[i+1]) return false;
            }
            else{
                if(nums[i]>nums[i+1]) return false;
            }
        }
        return true;
    }
};