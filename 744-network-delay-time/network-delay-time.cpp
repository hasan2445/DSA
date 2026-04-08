class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
       // int wt=adj[k]
        pq.push({0,k});
        int sum=0;
        vector<int>dist(n+1,1e9);
        //visited[0]=1;
        dist[k]=0;
        while(!pq.empty())
        {
            auto f=pq.top();
            pq.pop();
            int d=f.first;
            int nodes=f.second;
            if(d>dist[nodes]) continue;
            
            for(auto f:adj[nodes])
            {
                int w=f.second;
                int nt=f.first;
                if(d+w<dist[nt])
                {
                    dist[nt]=d+w;
                    pq.push({dist[nt],nt});
                }
            }
        }
       int mx=0;
       for(int i=1;i<dist.size();i++)
       {
        if(dist[i]==1e9) return -1;
        else mx=max(dist[i],mx);
       }
       return mx;

    }
};