class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        while(pq.size()>1){
             int l1 = pq.top();
             pq.pop();
             int l2 = pq.top();
             pq.pop();
             if(l1>l2){
                pq.push(l1-l2);
             }
        }
        if(!pq.empty()) return pq.top();
        return 0;
    }
};