class Twitter {
public:
    Twitter() {
        
    }
    stack<pair<int,int>> st;
    unordered_map<int,set<int>>mpp;
    void postTweet(int userId, int tweetId) {
        st.push({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        stack<pair<int,int>> stu=st;
        vector<int>v;
        while(!stu.empty() && v.size()!=10){
            pair<int,int>p=stu.top();
            stu.pop();
            if(p.first==userId || mpp[userId].find(p.first)!=mpp[userId].end()){
                v.push_back(p.second);
            }
        }
        return v;
    }
    
    void follow(int followerId, int followeeId) {
        mpp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mpp[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */