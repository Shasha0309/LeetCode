class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0;
        int far = 0;
        int jump =0;
        while(r<nums.size()-1){
            far=0;
            for(int i=l;i<=r;i++){
                far = max(far,nums[i]+i);
            }
            l=r+1;
            r=far;
            jump++;
        }
        return jump;
    }
};