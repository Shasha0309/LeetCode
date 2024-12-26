class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       /* if(s.length()==0) return 0;
        int maxlen = INT_MIN;
        for(int i=0;i<s.length();i++){
            unordered_set<char> st;
            for(int j=i;j<s.length();j++){
                if(st.find(s[j])!=st.end()){
                    maxlen = max(maxlen,j-i);
                    break;
                }
                st.insert(s[j]);
            }
        }
        return maxlen;*/
          unordered_set<char> st; // To store unique characters in the current window
    int maxlen = 0;         // To track the maximum length of substring
    int left = 0;           // Left pointer for the sliding window

    for (int right = 0; right < s.length(); right++) {
        // If a duplicate character is found, shrink the window from the left
        while (st.find(s[right]) != st.end()) {
            st.erase(s[left]);
            left++;
        }
        // Add the current character to the set
        st.insert(s[right]);
        // Update the maximum length
        maxlen = max(maxlen, right - left + 1);
    }

    return maxlen;
    }
};