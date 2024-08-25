class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int p=i+1;p<n;p++){
                if (p > i + 1 && nums[p]==nums[p - 1]) continue;
            int j = p+1;
            int k = n-1;
            while(j<k){
               long long sum = nums[i];
               sum += nums[j];
                sum += nums[k];
                sum += nums[p];
                if(sum>target) k--;
                else if(sum<target) j++;
                else{
                    vector<int> temp = {nums[i],nums[j],nums[k],nums[p]};
                    sort(temp.begin(),temp.end());
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
            }
        }
        return ans;
    }
};