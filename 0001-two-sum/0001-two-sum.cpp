class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*map<long long, int> mpp;
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];

            long long rem = sum-target;
            if()
            if(mpp.find(rem)!=mpp.)
        }*/
        vector<int> ans(2,0);
        for(int i=0;i<nums.size();i++){
            long long sum = nums[i];
            for(int j=i+1;j<nums.size();j++){
                if(target-sum==nums[j]){
                    ans[0] = i;
                    ans[1] = j;
                    break;
                }
            }
        }
        return ans;
    }
};