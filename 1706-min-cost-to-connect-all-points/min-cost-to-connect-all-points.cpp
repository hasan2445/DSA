class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& point) {
        vector<vector<pair<int,int>>>adj(point.size());
        for(int i=0;i<point.size();i++)
        {
            for(int j=i+1;j<point.size();j++)
            {
                int dis=abs(point[i][0]-point[j][0])+abs(point[i][1]-point[j][1]);
                adj[i].push_back({j,dis});
                adj[j].push_back({i,dis});
            }

        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,0});
        int sum=0;
        vector<int>visited(point.size(),0);
        while(!pq.empty())
        {
            auto f=pq.top();
            pq.pop();
            int d=f.first;
            int nodes=f.second;
            if(visited[nodes]) continue;
            visited[nodes]=1;
            sum+=d;
            for(auto nbr:adj[nodes])
            {
                pq.push({nbr.second,nbr.first});
                
            }
        }
        return sum;

    }
};