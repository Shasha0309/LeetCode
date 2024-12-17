class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0;
        int farth=0;
        int l=0;
        int r=0;
        while(r<nums.size()){
            if(r==nums.size()-1) return jump;
           farth=max(nums[l],nums[r]);
           l=r+1;
           r+=farth; 
           jump++;
        }
        return jump;
    }
};