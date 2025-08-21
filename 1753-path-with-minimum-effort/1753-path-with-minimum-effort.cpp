class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        int drow[4] = {0,1,0,-1};
        int dcol[4] = {1,0,-1,0};
        while(!pq.empty()){
            auto it = pq.top();
            int r = it.second.first;;
            int c = it.second.second;
            int dis = it.first;
            pq.pop();
            if(r==n-1 && c==m-1) return dis;
            for(int i=0;i<4;i++){
                int nr = r+drow[i];
                int nc = c+dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int newdif = max(abs(heights[r][c]-heights[nr][nc]),dis);
                    if(newdif<dist[nr][nc]){
                        pq.push({newdif,{nr,nc}});
                        dist[nr][nc]=newdif;
                    }
                }
            }
        }
        return 0;
    }
};