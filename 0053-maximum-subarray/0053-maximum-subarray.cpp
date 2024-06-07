class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = 0;
        int sum = INT_MIN;
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            current_sum += nums[i];
            sum = max(current_sum,sum);
           if(current_sum<0) current_sum=0;
            
        }
        return sum;
    }
};