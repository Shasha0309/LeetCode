class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        vector<int> v;
        for(int i=0;i<nums2.size();i++){
            while(!st.empty() && st.top()<nums2[i]){
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            if(mp[nums1[i]]){
                v.push_back(mp[nums1[i]]);
            }
            else{
                v.push_back(-1);
            }
        }
        return v;
    }
};