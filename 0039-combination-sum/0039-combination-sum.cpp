class Solution {
public:
void solve(vector<vector<int>>& ans,int ind,int target,vector<int>& nums, vector<int>&out){
       if(ind==nums.size()){
        if(target==0) ans.push_back(out);
        return; 
       }
       if(nums[ind]<=target){
        out.push_back(nums[ind]);
        solve(ans,ind,target-nums[ind],nums,out);
        out.pop_back();
       }
       solve(ans,ind+1,target,nums,out);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> out;
        solve(ans,0,target,candidates,out);
        return ans;
    }
};