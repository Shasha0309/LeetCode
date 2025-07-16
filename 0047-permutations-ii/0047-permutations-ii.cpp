class Solution {
    void sol(vector<int> nums,vector<int> list,vector<bool> used,vector<vector<int>>& ans){
        if(list.size()==nums.size()){
            ans.push_back(list);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            if(i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;

             used[i]=1;
            list.push_back(nums[i]);
           
            
            sol(nums,list,used,ans);

            used[i]=0;
            list.pop_back();

        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> list; 
        vector<bool> used(nums.size(),0);
        sol(nums,list,used,ans);
        return ans;
    }
};