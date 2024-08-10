class Solution {
    bool ifposib(string &s1,string &s2){
        if(s1.size()!=s2.size()+1) return false;
        int first = 0;
        int second = 0;
        while(first<s1.size()){
            if(s1[first]==s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(first==s1.size() && second==s2.size()) return true;
        return false;
    }
    bool static comp(string& s1,string& s2){
        return s1.size()<s2.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n = words.size();
        vector<int> dp(n,1);
        int maxi = 1;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(ifposib(words[i],words[j]) && 1+dp[j]>dp[i]){
                    dp[i] = 1+dp[j];
                }
            }
            if(maxi<dp[i]){
                maxi = dp[i];
            }
        }
        return maxi;
    }
};