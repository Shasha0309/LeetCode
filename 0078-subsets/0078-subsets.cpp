class Solution {
    void sol(int ind,vector<int> nums,vector<vector<int>>& ans,vector<int>& path){
        ans.push_back(path);
        for(int i=ind;i<nums.size();i++){
            path.push_back(nums[i]);
            
            sol(i+1,nums,ans,path);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        sol(0,nums,ans,path);
        //ans.push_back(path);
        return ans;
    }
};