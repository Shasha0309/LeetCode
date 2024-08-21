class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n = nums.size();
       int total = 0;
        for(int i=0;i<n;i++){
            total = total+nums[i];
        }
          long long totalSum = static_cast<long long>(n) * (n + 1) / 2;
          return totalSum-total;
    }
};