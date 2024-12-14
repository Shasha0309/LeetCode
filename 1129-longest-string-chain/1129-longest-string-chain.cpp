class Solution {
    bool compare(string word1,string word2){
        if(word1.size()!=word2.size()+1) return false;
        int first=0;
        int sec=0;
        //int n = word1;
        //int m = word2;
        while(first<word1.size()){
            if(word1[first]==word2[sec] && sec<word2.size()){
                first++;
                sec++;
            }
            else{
                first++;
            }
        }
        return first==word1.size() && sec==word2.size();
    }

    bool static comp(string& s1,string& s2){
        return s1.size()<s2.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),comp);
        int ans=0;
        vector<int> dp(n,1); //hash(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<=i-1;prev++){
                if(compare(words[i],words[prev])){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};