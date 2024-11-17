class Solution {
    void findnse(int nse[],vector<int> arr){
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
    
    void findpse(int pse[],vector<int> arr){
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
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
      int mod = (int)(1e9+7);
        int nse[n];
        int pse[n];
        findnse(nse,arr);
        findpse(pse,arr);
        int cnt = 0;
        for(int i=0;i<n;i++){
            int left = i-pse[i];
            int right = nse[i]-i;
             
            cnt = (cnt + (left*right*1ll*arr[i])%mod)%mod;
        }
        return cnt;
    }
};