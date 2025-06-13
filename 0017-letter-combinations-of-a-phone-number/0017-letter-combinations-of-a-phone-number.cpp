class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        unordered_map<char,string> diglet = {
            {'2',"abc"},
            {'3',"def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        backtrack(digits,0,"",ans,diglet);
        return ans;
    }
    void backtrack(const string& digits,int idx,string res,vector<string>& cobo,unordered_map<char,string>& diglet){
        if(idx==digits.size()){
            cobo.push_back(res);
            return;
        }
        string letters = diglet.at(digits[idx]);
        for(char letter:letters){
            backtrack(digits,idx+1,res+letter,cobo,diglet);
        }
    }
};