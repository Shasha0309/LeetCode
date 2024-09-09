class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lefts = 0;
        int rights = 0;
        int maxsum = 0;
        for(int i=0;i<k;i++){
            lefts += cardPoints[i];
             maxsum = lefts;
        }
        int rghtind = cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            lefts =  lefts-cardPoints[i];
            rights += cardPoints[rghtind];
            rghtind--;
            maxsum = max(maxsum,lefts+rights);
        }
        return maxsum;
    }
};