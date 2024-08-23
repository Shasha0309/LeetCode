class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int ele;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            if(cnt==0) {
                ele = nums[i];
                cnt++;
                continue;
            }
            if(nums[i]==ele){
                cnt++;
            }
            else if(nums[i]!=ele){
                cnt--;
            }
        }
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele) ans++;
        }
        if(ans>n/2) return ele;
        return -1;
    }
};