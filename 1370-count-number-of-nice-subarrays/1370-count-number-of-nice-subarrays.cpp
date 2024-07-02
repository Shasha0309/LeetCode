class Solution {
public:
int helper(vector<int>nums,int goal){
    int l=0;
    int r=0;
    int cnt = 0;
    int sum=0;
    if(goal<0) return 0;
    while(r<nums.size()){
        //sum+=nums[r];
        if(nums[r]%2!=0) sum++;
        while(sum>goal){
            //sum=sum-nums[l];
            if(nums[l]%2!=0)sum--;
            l++;
        }
        cnt+=(r-l+1);
        r++;
    }
    return cnt;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        /*int l=0;
        int r=0;
        map<int,int> mpp;
        for(int i=0;i<2;i++){
            mpp[i] = 0;
        }
        int cnt = 0;
        while(r<nums.size()){
            if(nums[r]%2==0){
                mpp[1]++;
            }
            else{
                mpp[0]++;
            }
            while(mpp[0]>k && l<=r){
                cnt++;
                if(nums[l]%2==0){
                    mpp[1]--;
                }
                else{
                    mpp[0]--;
                }
                l++;
            }
            r++;
        }
        return cnt;*/
        return helper(nums,k)-helper(nums,k-1);
    }
};