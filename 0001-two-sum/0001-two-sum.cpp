class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        int num1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            num1 = target - nums[i];
            if(mp.find(num1)!=mp.end()){
              ans.push_back(i);
              ans.push_back(mp[num1]);
              break;
            }
            mp.insert({nums[i],i});
        }
         return ans;
    }
};