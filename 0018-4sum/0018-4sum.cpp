class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        //if(n<4) return 0;
        int j;
        int k;
        int l;
        long long res;
        long long res1;
        for(int i=0;i<n-3;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                for(int j=i+1;j<n-2;j++){
                if(j==i+1 || (j>i+1 && nums[j]!=nums[j-1])){
                     k=j+1;
                l=n-1;
                res1 = nums[i]+nums[j];
                res = target-(res1);
                while(k<l){
                    if(nums[k]+nums[l]==res){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        while(k<l && nums[k]==nums[k+1])k++;
                        while(k<l && nums[l]==nums[l-1])l--;
                        k++;
                        l--;
                    }
                    else if(nums[k]+nums[l]<res){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }      
            }
        }
        return ans;
    }
};