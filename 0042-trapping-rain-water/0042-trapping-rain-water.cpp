class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxl(n,0);
        vector<int> maxr(n,0);
        maxl[0] = height[0];
        maxr[height.size()-1] = height[height.size()-1];
        for(int i=1;i<n;i++){
            if(height[i]>maxl[i-1]) maxl[i]=height[i];
            else maxl[i]=maxl[i-1];
        }
        for(int i=height.size()-2;i>=0;i--){
            if(height[i]>maxr[i+1]) maxr[i]=height[i];
            else maxr[i]=maxr[i+1];
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = ans+abs(height[i]-(min(maxl[i],maxr[i])));
        }
        return ans;
    }
};