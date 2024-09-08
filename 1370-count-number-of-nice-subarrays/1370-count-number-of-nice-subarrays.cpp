class Solution {
    int solve(vector<int> nums,int k){
        int l = 0;
        int r = 0;
        int cnt = 0;
        int odd = 0;
        if(k<0) return 0;
        while(r<nums.size()){
            if(nums[r]%2!=0){
                odd++;
            }
            while(odd>k){
                if(nums[l]%2!=0){
                    odd--;
                }
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};