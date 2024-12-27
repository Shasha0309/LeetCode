class Solution {
    int solve(vector<int>& nums,int k){
        unordered_map<int,int> st;
        int l = 0;
        int r = 0;
        int cnt = 0;
        if(k<=0) return 0;
        while(r<nums.size()){
            st[nums[r]]++;
            while(st.size()>k){
                st[nums[l]]--;
                if(st[nums[l]]==0) st.erase(nums[l]);
                l++;
            }
            
        
        cnt+=(r-l+1);
        r++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);

    }
};