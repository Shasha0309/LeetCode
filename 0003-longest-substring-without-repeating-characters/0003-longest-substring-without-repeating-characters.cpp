class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int ans = 0;
        unordered_set<char> st;
        for(int rig = 0;rig<s.length();rig++){
            while(st.find(s[rig])!=st.end()){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[rig]);
            ans = max(ans,rig-left+1);
        }
        return ans;
    }
};