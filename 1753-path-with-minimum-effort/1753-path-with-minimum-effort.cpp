class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> dif(n, vector<int>(m, 1e9));
        dif[0][0] = 0;
        int row[] = {-1, 0, +1, 0};
        int col[] = {0, +1, 0, -1};
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int currDif = it.first;
            int i = it.second.first;
            int j = it.second.second;
            if (i == n - 1 && j == m - 1)
                return currDif; // already reached
            for (int k = 0; k < 4; k++) {
                int r = i + row[k];
                int c = j + col[k];
                if ((r >= 0 && r <= n - 1 && c <= m - 1 && c >= 0) &&
                    abs(heights[i][j] - heights[r][c]) < dif[r][c]) {
                    dif[r][c] = abs(heights[i][j] - heights[r][c]);
                    pq.push({max(currDif, dif[r][c]), {r, c}});
                }
            }
        }
        return dif[n - 1][m - 1];
    }
};