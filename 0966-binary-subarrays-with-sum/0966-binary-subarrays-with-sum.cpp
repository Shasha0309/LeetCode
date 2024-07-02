class Solution {
public:
int helper(vector<int>nums,int goal){
    int l=0;
    int r=0;
    int cnt = 0;
    int sum=0;
    if(goal<0) return 0;
    while(r<nums.size()){
        sum+=nums[r];
        while(sum>goal){
            sum=sum-nums[l];
            l++;
        }
        cnt+=(r-l+1);
        r++;
    }
    return cnt;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums,goal)-helper(nums,goal-1);
    }
};