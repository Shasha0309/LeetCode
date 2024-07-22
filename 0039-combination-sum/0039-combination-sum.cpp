class Solution {
    void solve(int ind,vector<int> &nums,vector<vector<int>> &ans,vector<int> &out,int target){
        if(ind==nums.size()){
        if(target==0){
            ans.push_back(out);
        }
        return;
        }
        if(nums[ind]<=target){
            out.push_back(nums[ind]);
            solve(ind,nums,ans,out,target-nums[ind]);
            out.pop_back();
        }
        solve(ind+1,nums,ans,out,target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> out;
        solve(0,candidates,ans,out,target);
        return ans;
    }
};