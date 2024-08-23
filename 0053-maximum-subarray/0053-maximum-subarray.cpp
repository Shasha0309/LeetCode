class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long curr_sum = 0;
        long long sum = INT_MIN;
        for(int i=0;i<nums.size();i++){
            curr_sum += nums[i];
            sum = max(sum,curr_sum);
            if(curr_sum<0) curr_sum = 0;
        }
        return sum;
    }
};