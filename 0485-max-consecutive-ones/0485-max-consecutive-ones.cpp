class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int fis = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) ans=0;
            else ans++;
            fis = max(ans,fis);
        }
        return fis;
    }
};