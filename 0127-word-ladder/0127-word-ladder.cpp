class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> sot(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        sot.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word==endWord) return steps;
            for(int i=0;i<word.size();i++){
                char orgi=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(sot.find(word)!=sot.end()){
                        sot.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = orgi;
            }
        }
        return 0;
    }
};