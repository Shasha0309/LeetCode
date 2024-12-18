class Solution {
    bool static comp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int res = intervals[0][1];
        int cnt = 0;
        int i=1;
        while(i<intervals.size()){
            if(res>intervals[i][0]){
                cnt++;
            }
            else{
                res=intervals[i][1];
            }
            i++;
        }
        return cnt;
    }
};