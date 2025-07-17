class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mpp;
        for(auto num:strs){
            string word = num;
            sort(word.begin(),word.end());
            mpp[word].push_back(num);
        }
        for(auto x:mpp){
            ans.push_back(x.second);
        }
        return ans;
    }
};