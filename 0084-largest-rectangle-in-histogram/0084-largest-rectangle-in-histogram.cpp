class Solution {
    /*void findnse(int nse[],const vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n-1:st.top()-1;
            st.push(i);
        }
    }
    
    void findpse(int pse[],const vector<int>& arr){
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? 0:st.top()+1;
            st.push(i);
        }
    }*/
    void findnse(int nse[],const vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n:st.top();
            st.push(i);
        }
    }
    
    void findpse(int pse[],const vector<int>& arr){
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1:st.top();
            st.push(i);
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();
        int nse[n];
        int pse[n];
        findnse(nse,heights);
        findpse(pse,heights);
        int cnt = 0;
        for(int i=0;i<n;i++){
            cnt = max(cnt,(nse[i]-pse[i]-1)*heights[i]);
        }
        return cnt;
        /*int n = heights.size();
      stack < int > st;
      int leftsmall[n], rightsmall[n];
      for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
          st.pop();
        }
        if (st.empty())
          leftsmall[i] = 0;
        else
          leftsmall[i] = st.top() + 1;
        st.push(i);
      }
      // clear the stack to be re-used
      while (!st.empty())
        st.pop();

      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
          st.pop();

        if (st.empty())
          rightsmall[i] = n - 1;
        else
          rightsmall[i] = st.top() - 1;

        st.push(i);
      }
      int maxA = 0;
      for (int i = 0; i < n; i++) {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
      }
      return maxA;*/
    }
};