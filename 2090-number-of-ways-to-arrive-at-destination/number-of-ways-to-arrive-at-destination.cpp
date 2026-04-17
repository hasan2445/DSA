class Solution {
public:

    int countPaths(int x, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(x);
        const int mod=1e9+7;
        vector<long long>dist(x,1e18);
        vector<int>way(x,0);
        for(auto i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});

        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>q;
        q.push({0,0});
        dist[0]=0;
        way[0]=1;
        while(!q.empty())
        {
            auto f=q.top();
            q.pop();
            long long d=f.first;
            int node=f.second;
            if(dist[node]<d) continue;
            for(auto &it:adj[node])
            {
                int n=it.first;
                int w=(it.second);
                if((d+w)<dist[n])
                {
                    dist[n]=d+w;
                    q.push({d+w,n});
                    way[n]=way[node];
                }
                else if(dist[n]==d+w)
                {
                    way[n]=(way[n]+way[node])%mod;
                }
                
            }


        }
        return way[x-1];
    }
};