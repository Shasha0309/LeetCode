class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current_sum = 0;
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0) current_sum = 0;
            current_sum += nums[i];
            
            sum = max(current_sum,sum);
        }
        return sum;
    }
};