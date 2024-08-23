class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            if(mpp[nums[i]]>=n/2){ return nums[i]; }
            mpp[nums[i]] += 1;
        }
        return 0;
    }
};