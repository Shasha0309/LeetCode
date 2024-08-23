class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<long long, int> mpp;
        long long sum = 0;
        vector<int> ans(2,0);
        for(int i=0;i<nums.size();i++){
            sum = nums[i];

            long long rem = target-sum;
            if(mpp.find(rem)!=mpp.end()){
                ans[0] = mpp[rem];
                ans[1] = i;
                break;
            }
            if(mpp.find(nums[i])==mpp.end()){
                mpp[nums[i]] = i;
            }
        }
        return ans;
    }
};