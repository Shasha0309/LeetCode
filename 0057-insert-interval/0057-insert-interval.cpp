class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i=0;
        while(i<intervals.size() && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        
        while(i<intervals.size() && intervals[i][0]<=newInterval[1]){
            newInterval[0] = min(intervals[i][0],newInterval[0]);
            newInterval[1] = max(intervals[i][1],newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);
        for(int j=i;j<intervals.size();j++){
            ans.push_back(intervals[j]);
        }
        return ans;

    }
};