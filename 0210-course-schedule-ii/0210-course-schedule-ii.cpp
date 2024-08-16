class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto& it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
         queue<int> q;
	    vector<int> indeg(numCourses,0);
	    for(int i=0;i<numCourses;i++){
	        for(auto it : adj[i]){
	            indeg[it]++;
	        }
	    }
	    for(int i=0;i<numCourses;i++){
	        if(indeg[i]==0){
	            q.push(i);
	        }
	    }
	    vector<int> ans;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto it : adj[node]){
	            indeg[it]--;
	            if(indeg[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    if(ans.size()==numCourses) return ans;
        return {};
    }
};