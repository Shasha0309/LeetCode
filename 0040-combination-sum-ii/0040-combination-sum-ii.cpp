class Solution {
    void solve(vector<vector<int>>& ans,int ind,vector<int>& out,vector<int>& nums,int target){
        
            if(target==0) {
                ans.push_back(out);
            return;
            }
        
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;
            out.push_back(nums[i]);
            solve(ans,i+1,out,nums,target-nums[i]);
            out.pop_back();   
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> out;
        solve(ans,0,out,candidates,target);
        return ans;
    }
};