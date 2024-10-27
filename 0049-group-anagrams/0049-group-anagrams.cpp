class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*vector<vector<string>> ans;
        if(strs.empty()) return ans;
        int n=strs.size();
        vector<int> mint(n,0);
        unordered_map<char,int> mpp;
        for(int l=0;l<strs.size();l++){
            vector<string> res;
            string prefix = strs[l];
            res.push_back(prefix);
            int r=l+1;
            for(char c:prefix){
                mpp[c]++;
            }
            while(r<strs.size()&& mint[r]==0){
                for(char c:strs[r]){
                    if(mpp[s[r]]==0) break;
                    mpp[c]--;
                }
                r++;
            }
            ans.push_back(res);
        }
        return ans;*/
        unordered_map<string,vector<string>> mpp;
        for(auto x:strs){
            string word = x;
            sort(word.begin(),word.end());
            mpp[word].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto x:mpp){
            ans.push_back(x.second);
        }
        return ans;
    }
};