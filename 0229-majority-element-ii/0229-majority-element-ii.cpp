class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int res = n/3;
        vector<int> ans;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto x:mpp){
            int element = x.first;
            int count = x.second;
            if(count>res){
                ans.push_back(element);
            }
        }
        return ans;
    }
};