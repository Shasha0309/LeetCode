class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> pq;
        for(vector<int> v:points){
            int x = v[0];
            int y = v[1];
            int i = (x*x)+(y*y);
            pq.push({i,v});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
          ans.push_back(pq.top().second);
          pq.pop();
        }
        return ans;
    }
};