class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0;
        int farth=0;
        int l=0;
        int r=0;
        while(r<nums.size()-1){
            for(int i=l;i<=r;i++){
           farth=max(farth,nums[i]+i);
            }
           l=r+1;
           r=farth; 
           jump++;
        }
        return jump;
    }
};