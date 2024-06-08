class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 1;
        if(n==0) return 0;
        unordered_set <int> mpp;
        for(int i=0;i<n;i++){
            mpp.insert(nums[i]);
        }
        for(auto it : mpp){
            if(mpp.find(it -1)==mpp.end()){
            int cnt = 1;
            int x = it;
            while(mpp.find(x+1)!=mpp.end()){
                x=x+1;
                cnt++;
            }
            longest = max(longest,cnt);
            }
        }
        return longest;
    }
};