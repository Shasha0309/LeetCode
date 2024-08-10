class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1), hash(n);
        int maxi = 1;
        int lastIndex = 0;
        for(int i=0;i<nums.size();i++){
            hash[i] = i;
            for(int j=0;j<i;j++){
            if(nums[i]%nums[j]==0 && dp[i]<1+dp[j]){
                dp[i] = 1+dp[j];
                hash[i] = j;
            }
        }
        if(maxi<dp[i]){
            maxi = dp[i];
            lastIndex = i;
        }
    }
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        sort(temp.begin(),temp.end());
        return temp;
    }
};