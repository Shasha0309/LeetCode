class Solution {
public:
    int toThe(vector<int>nums,int k){
        int l=0;
        int r=0;
        int cnt=0;
        int n=nums.size();
        unordered_map<int,int> mySet;
        if(k<=0) return 0;
        while(r<n){
             mySet[nums[r]]++;
            while(mySet.size()>k){
                mySet[nums[l]]--;
                if(mySet[nums[l]]==0){
                    mySet.erase(nums[l]);
                }
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return toThe(nums,k) - toThe(nums,k-1);
    }
};