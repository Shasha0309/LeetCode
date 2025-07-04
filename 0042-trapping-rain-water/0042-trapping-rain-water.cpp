class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxl(n,0);
        vector<int> maxr(n,0);
        maxl[0] = height[0];
        maxr[height.size()-1] = height[height.size()-1];
        for(int i=1;i<n;i++){
            maxl[i] = max(maxl[i-1],height[i]);
        }
        for(int i=height.size()-2;i>=0;i--){
            maxr[i] = max(maxr[i+1],height[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = ans+abs(height[i]-(min(maxl[i],maxr[i])));
        }
        return ans;
    }
};