class Solution {
public:
bool static comp(vector<int> a,vector<int> b){
    return a[1]<b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        int end = intervals[0][1];
        int i=1;
        while(i<n){
            if(intervals[i][0]>=end){
                end=intervals[i][1];
            }
            else{cnt++;}
            i++;
        }
        return cnt;
    }
};