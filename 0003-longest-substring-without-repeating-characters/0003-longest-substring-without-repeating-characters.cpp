class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ans;
        int left=0;
        int maxlength=0;
        for(int right = 0;right<s.length();right++){
            if(ans.count(s[right])==0){
            ans.insert(s[right]);
            maxlength = max(maxlength,right-left+1);
            }
            else{
                while(ans.count(s[right])){
                    ans.erase(s[left]);
                    left++;
                }
                ans.insert(s[right]);
            }
        }
        return maxlength;
    }
};