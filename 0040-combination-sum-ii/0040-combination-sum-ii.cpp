class Solution {
    void solve(int ind,vector<vector<int>> &ans,vector<int> &out,int target,vector<int>&nums){
         if(target==0){
            ans.push_back(out);
            return;
            }
        
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;
            out.push_back(nums[i]);
        solve(i+1,ans,out,target-nums[i],nums);
        out.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> out;
        solve(0,ans,out,target,candidates);
        return ans;
    }
};