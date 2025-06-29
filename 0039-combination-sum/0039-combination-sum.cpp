class Solution {
    void sol(vector<vector<int>>& ans,int ind,vector<int>& nums,int target,vector<int>& out){
        if(ind==nums.size()){
            if(target==0) ans.push_back(out);
                return;
            
        }
        if(nums[ind]<=target){
            out.push_back(nums[ind]);
            sol(ans,ind,nums,target-nums[ind],out);
            out.pop_back();
        }
        sol(ans,ind+1,nums,target,out);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> inu;
        sol(ans,0,candidates,target,inu);
        return ans;
    }
};