class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& suc, int start, int end) {
        // remove this
 
        vector<vector<pair<int,double>>>adj(n);
        vector<double>dist(n,0);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],suc[i]});
            adj[edges[i][1]].push_back({edges[i][0],suc[i]});
        }
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start});
        dist[start]=1.0;
        while(!pq.empty())
        {
            auto f=pq.top();
            pq.pop();
            auto pr=f.first;
            int node=f.second;
            if(end==node) return pr;
            if(dist[node]>pr) continue;
            
            for(auto nbr:adj[node])
            {
                auto n=nbr.first;
                auto d=nbr.second;
                double nxt=pr*d;
                if(nxt>dist[n]) 
                {
                dist[n]=dist[node]*d;
                pq.push({dist[n],n});
                }
            }
        }
        return dist[end];
    }
};