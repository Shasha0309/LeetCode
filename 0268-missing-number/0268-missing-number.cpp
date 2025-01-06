class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            total += nums[i];
        }
        long long res = static_cast<long long> (n)*(n+1)/2;
        return res-total;
    }
};