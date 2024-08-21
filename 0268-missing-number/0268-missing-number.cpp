class Solution {
public:
    int missingNumber(vector<int>& nums) {
       // int n = max_element(nums.begin(),nums.end());
       int total = 0;
        for(int i=1;i<nums.size()+1;i++){
            total+=i;
        }
        //int ans = 0;
        for(int i=0;i<nums.size();i++){
            total = total-nums[i];
        }
        return total;
    }
};