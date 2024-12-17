class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            if(maxi<i) return 0;
            maxi = max(maxi,nums[i]+i);
        }
        return 1;
    }
};