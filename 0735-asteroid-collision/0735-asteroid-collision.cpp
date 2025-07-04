class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }
             else{
                  while(!st.empty() && st.top()>0 &&  st.top()<abs(asteroids[i])){
                           st.pop();
                  }
                  
                  if(!st.empty() && st.top()==abs(asteroids[i])){
                      st.pop();
                  }
                     else if(st.empty() && asteroids[i]<0 || (st.top()<0 && asteroids[i]<0)){
                         st.push(asteroids[i]); }                
              }
            
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.insert(ans.begin(), st.top());
            st.pop();
        }
        return ans;
    }
};