class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>>pq;
        for(int i=0;i<stones.size();i++)
        {
            pq.push(stones[i]);
        }
        while(pq.size()>1)
        {
            auto f=pq.top();
            pq.pop();
            auto q=pq.top();
            pq.pop();
            
             pq.push(abs(f-q));
        }
        return pq.top();
    }
};