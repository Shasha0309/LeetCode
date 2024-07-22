class Solution {
    void solve(int ind,vector<vector<int>> &ans,vector<int> &out,vector<int> &nums){
            ans.push_back(out);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
        out.push_back(nums[i]);
        solve(i+1,ans,out,nums);
        out.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> out;
        solve(0,ans,out,nums);
        return ans;
    }
};