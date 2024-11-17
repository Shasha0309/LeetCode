class Solution {
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
    void findnge(int nge[],const vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            nge[i] = st.empty() ? n:st.top();
            st.push(i);
        }
    }
    
    void findpge(int pge[],const vector<int>& arr){
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            pge[i] = st.empty() ? -1:st.top();
            st.push(i);
        }
    }
public:
    long long subArrayRanges(vector<int>& nums) {
         int n = nums.size();
      int mod = (int)(1e9+7);
        int nse[n];
        int pse[n];
        int nge[n];
        int pge[n];
        findnse(nse,nums);
        findpse(pse,nums);
        findnge(nge,nums);
        findpge(pge,nums);
        long long cntmin = 0;
        long long cntmax=0;
        for(int i=0;i<n;i++){
            long long leftmin = i-pse[i];
            long long rightmin = nse[i]-i;
            long long leftmax = i-pge[i];
            long long rightmax = nge[i]-i; 
            //cntmin = (cntmin + (leftmin*rightmin*1ll*nums[i])%mod)%mod;
            //cntmax = (cntmax + (leftmax*rightmax*1ll*nums[i])%mod)%mod;
            cntmin = (cntmin + (leftmin * rightmin * nums[i]));
        cntmax = (cntmax + (leftmax * rightmax  * nums[i]));
        }
        return cntmax - cntmin;
    }
};