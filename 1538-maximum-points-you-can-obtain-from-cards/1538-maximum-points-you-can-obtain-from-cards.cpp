class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        int lsum = 0;
        int rsum = 0;
        int l = k-1;
        int r = n-1;
        for(int i=l;i>=0;i--){
            lsum+=cardPoints[i];
              sum = lsum;
        }
      
        for(int i=l;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[r];
            r--;
        
        sum=max(sum,lsum+rsum);
        }
        
       // int cnt;
        return sum;
    }
};