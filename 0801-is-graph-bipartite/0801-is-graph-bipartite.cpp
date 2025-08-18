class Solution {
    bool dfs(int i,int col,int color[],vector<vector<int>>& graph){
        color[i]=col;
        for(auto it:graph[i]){
            if(color[it]==-1){
                if(dfs(it,!col,color,graph)==false) return false;
            }
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        int color[V];
        for(int i=0;i<V;i++) color[i]=-1;
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,graph)==false) return false;
            }
        }
      return true;
    }
};